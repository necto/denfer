/**
 * Header file of simple performance counter on Linux.
 * This perf counter performs sampling of RIP from given process
 * with given time intervals.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "perf_impl.hpp"
#include <QThread>
#include <QTimer>
#include <sys/types.h>

namespace perf
{

namespace lin
{

/**
 * Worker class to be running inside separate thread.
 * Class is based upon QTimer to perform simple data peek
 * every N msec.
 */
class SimpleCounterWorker : public QTimer
{
    Q_OBJECT
public:
    /**
     * Construct new worker to be connected to _pid process.
     */
    SimpleCounterWorker( pid_t _pid);

public slots:
    /**
     * Perform thread-specific initialization and start counting.
     */
    void startCount();

    /**
     * Get sample data from process.
     */
    void doCount();

    /**
     * Cut currently counted data and pass it back.
     */
    void getValues();

signals:
    /**
     * Signal to report counted data.
     */
    void valuesReady( CounterValues* values);

private:
    /**
     * Pid of the process to be attached to.
     */
    pid_t pid;
};

class SimpleCounter : public PerfCounter
{
public:
    /**
     * UUID of simple counter
     */
    static const QUuid uuid;

    /**
     * Constructor counter for given process
     * and with given sampling rate.
     */
    SimpleCounter( pid_t _pid, int msec);

    void start();

    void stop();

    void reset();

    void requestValues();
signals:
    /**
     * Signal to request counted values from worker thread.
     * Values are passed back through (@link valuesReady
     */
    void requestSignal();
private:
    /**
     * Worker object to perform counting
     * in separate thread
     */
    SimpleCounterWorker* worker;

    /**
     * Thread for counter worker
     */
    QThread* thread;

    /**
     * Pid to be traced
     */
    pid_t pid;
};

}; // namespace lin

}; // namespace perf
