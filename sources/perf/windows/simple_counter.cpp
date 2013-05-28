/**
 * Implementation of simple performance counter on Linux.
 * This perf counter performs sampling of RIP from given process
 * with given time intervals.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#include "simple_counter.hpp"

namespace perf
{

namespace lin
{

SimpleCounterWorker::SimpleCounterWorker( pid_t _pid) : QTimer(), pid( _pid) 
{
    /* Connect timer timeout event to peekdata action */
    QObject::connect(this, SIGNAL(timeout()), this, SLOT(doCount()));

    /* Create internal data storage */
    values = new SimpleValues_t;
};

void SimpleCounterWorker::startCount()
{
    /**
     * Note: at this point worker must be already incapsulated
     * into separate thread to ensure proper ptrace_attach.
     */
    long ptrace_ret = ptrace(PTRACE_ATTACH, pid,
                             NULL, NULL);
    
    if ( ptrace_ret == -1)
    {
        // FIXME: Add error processing here
    }

    wait(NULL);
    ptrace(PTRACE_CONT, pid, NULL, NULL);

    /* Start timer */
    this->start();
}

void SimpleCounterWorker::doCount()
{
    struct user_regs_struct regs;
    quint64 rip, val;

    kill( pid, SIGSTOP);
    wait(NULL);
    ptrace(PTRACE_GETREGS, pid,                                                                                                                                                                  
            NULL, &regs);                                                                                                                                                                                    
    //FIXME: add error processing here
    rip = regs.rip;

    val = 1 + values->value( rip);
    values->insert( rip, val);

    ptrace(PTRACE_CONT, pid,                                                                                                                                                                     
            NULL, NULL);
}

void SimpleCounterWorker::getValues()
{
    /* Do values cut off */
    SimpleValues_t* old = values;

    values = new SimpleValues_t;

    emit valuesReady( old);
}

PerfCounterImpl* SimpleCounter::create()
{
    return (PerfCounterImpl*)(new SimpleCounter());
}

void SimpleCounter::init( pid_t _pid, int msec)
{
    pid = _pid;
    worker = new SimpleCounterWorker( pid);
    QThread* thread = new QThread;

    worker->setInterval( msec);

    /* Connect thread and worker objects signals/slots */
    QObject::connect( thread, SIGNAL( started()), worker, SLOT( startCount()));
    QObject::connect( worker, SIGNAL( finished()), worker, SLOT( deleteLater()));
    QObject::connect( thread, SIGNAL( finished()), thread, SLOT( deleteLater()));
    QObject::connect( this, SIGNAL( valuesRequest()), 
                      worker, SLOT( getValues()));
    QObject::connect( worker, SIGNAL( valuesReady( SimpleValues_t*)), 
                      this, SLOT( receiveValues( SimpleValues_t*)));

    worker->moveToThread(thread);
}

void SimpleCounter::start()
{
    thread->start();
}

void SimpleCounter::stop()
{
    thread->quit();
}

void SimpleCounter::reset()
{
    //FIXME: add impl
}

void SimpleCounter::destroy()
{
    //FIXME: do cleanup
}

CounterValues* SimpleCounter::getValues()
{
    emit valuesRequest();

    /* Run dummy event loop to wait for asynchronous signal */
    QEventLoop loop;
    QObject::connect( this, SIGNAL( valuesReady()), &loop, SLOT( quit()));
    loop.exec();

    return (CounterValues*)values;
}

void SimpleCounter::receiveValues( SimpleValues_t* val)
{
    /* Convert values to external format */
    values = new CounterValuesImpl;
    SimpleTable_t* table = values->getSimpleTable();

    SimpleValues_t::const_iterator i;
    for ( i = val->begin();
          i != val->end();
          ++i )
    {
        PlainRecord rec;
        rec.key = i.key();
        rec.val = i.value();

        table->push_back( rec);
    }

    /* Destroy internal values */
    delete val;

    emit valuesReady();
}

const PerfCounterInfo SimpleCounter::info = SimpleCounter::doRegister();

PerfCounterInfo SimpleCounter::doRegister()
{
    PerfCounterInfo inf;
    inf.name = QString("SimpleCounter");
    inf.type = COUNTER_PLAIN; 
    inf.provider = PROVIDER_DENFER;
    inf.uuid = QUuid( "{00000000-0000-0000-0000-000000000001}");
    inf.factory = PerfCounterFactoryImpl::getInstance().registerCounter( inf.uuid, SimpleCounter::create);
    PerfManagerImpl::getInstance().registerCounter( inf);

    return inf;
}

}; // namespace lin

}; // namespace perf
