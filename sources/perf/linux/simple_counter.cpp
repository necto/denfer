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
};

void SimpleCounterWorker::startCount()
{
    // Do ptrace attach
    /**
     * Note: at this point worker must be already incapsulated
     * into separate thread to ensure proper ptrace_attach.
     */

    /* Start timer */
    this->start();
}

void SimpleCounterWorker::doCount()
{
    // Do ptrace peekdata of RIP
}

void SimpleCounterWorker::getValues()
{
    // Do values cut off

    emit valuesReady( (CounterValues*)NULL);
}

SimpleCounter::SimpleCounter( pid_t _pid, int msec) : pid( _pid)
{
    worker = new SimpleCounterWorker( pid);
    QThread* thread = new QThread;

    worker->setInterval( msec);

    /* Connect thread and worker objects signals/slots */
    QObject::connect( thread, SIGNAL( started()), worker, SLOT( startCount()));
    QObject::connect( worker, SIGNAL( finished()), worker, SLOT( deleteLater()));
    QObject::connect( thread, SIGNAL( finished()), thread, SLOT( deleteLater()));

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

void SimpleCounter::requestValues()
{
    emit requestSignal();
}

const QUuid SimpleCounter::uuid = QUuid( "{00000000-0000-0000-0000-000000000001}");

}; // namespace lin

        }; // namespace perf
