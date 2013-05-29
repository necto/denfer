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

#define SAMPLING_INTERVAL 100

namespace perf
{

namespace win
{

SimpleCounterWorker::SimpleCounterWorker(DWORD _pid)
    : QTimer()
    , pid(_pid)
    , loopCounter(0)
{
    /* Connect timer timeout event to peekdata action */
    QObject::connect(this, SIGNAL(timeout()), this, SLOT(doCount()));
    QObject::connect(this, SIGNAL(timeout()), this, SLOT(updateThreadList()));

    /* Create internal data storage */
    values = new SimpleValues_t;
}

void SimpleCounterWorker::startCount()
{
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
    hProcess = OpenProcess(
                PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
                FALSE,
                pid
    );
    if (hProcess == INVALID_HANDLE_VALUE) {
        // FIXME [avlechen] add err processing
    }

    this->start();
}

void SimpleCounterWorker::stop()
{
    QTimer::stop();
    threads.clear();
    SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
    CloseHandle(hProcess);
}

void SimpleCounterWorker::doCount()
{
    for (QVector<THREADENTRY32>::iterator it = threads.begin(); it != threads.end(); ++it) {
        HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, it->th32ThreadID);
        SuspendThread(hThread);

        CONTEXT c;
        memset(&c, 0, sizeof(CONTEXT));
        c.ContextFlags = CONTEXT_CONTROL;
        if (GetThreadContext(hThread, &c) == FALSE) {
            // FIXME [avlechen] add error processing
        }
        quint64 rip, val;
#ifdef _M_IX86
        rip = c.Eip;
#elif _M_X64
        rip = c.Rip;
#else
#error "Platform not supported!"
#endif
        val = values->value( rip) + 1;
        values->insert( rip, val);
        ResumeThread(hThread);
    }
}

void SimpleCounterWorker::updateThreadList()
{
    // now enum all threads for this processId
    if (loopCounter) {
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);

        // FIXME [avlechen] Strategy for exeptions is not defined
        if (hSnap == INVALID_HANDLE_VALUE) {
            DWORD exitCode = 0;
            if (GetExitCodeProcess(hProcess, &exitCode)) {
                if (exitCode != STILL_ACTIVE)  {
                    // FIXME [avlechen] Target program exited with code 0x%08x, exitCode;
                }
            } else {
                // FIXME [avlechen] CreateToolhelp32Snapshot failed with error code 0x%08x, GetLastError()
            }
        }

        threads.clear();
        THREADENTRY32 te;
        memset(&te, 0, sizeof(te));
        te.dwSize = sizeof(te);
        while (Thread32First(hSnap, &te) == FALSE) {
            if (te.th32OwnerProcessID == pid) {
                threads.push_back(te);
            }
        }
        // TODO [avlechen]: Possibly, we should store hSnap during sampling
        CloseHandle(hSnap);
    }
    loopCounter++;
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

void SimpleCounter::attach(Q_PID pid)
{
    worker = new SimpleCounterWorker( (DWORD)pid);
    QThread* thread = new QThread;

    worker->setInterval( SAMPLING_INTERVAL);

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
    worker->stop();
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

}; // namespace win

}; // namespace perf
