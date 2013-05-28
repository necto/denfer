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

#include <windows.h>
#include <TlHelp32.h>
#include "perfcounter.hpp"
#include "perfmanager.hpp"
#include <QThread>
#include <QTimer>

namespace perf
{

namespace win
{

/**
 * Internal data storage type
 */
typedef QMap<quint64,quint64> SimpleValues_t;

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
    SimpleCounterWorker( DWORD _pid);

    /**
     * @brief release all resources.
     */
    void stop();
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
     * Cut currently counted data and pass it back
     */
    void getValues();

signals:
    /**
     * Signal to report counted data.
     */
    void valuesReady( SimpleValues_t* values);

private:
    /**
     * Process id
     */
    DWORD pid;

    /**
     * Process handle to be attached to
     */
    HANDLE hProcess;

    /**
     * Vector for threads owned by process
     */
    QVector<THREADENTRY32> threads;

    /**
     * Counter used for sporadic update of thread list.
     */
    short loopCounter;

    /**
     * Internal storage class
     * FIXME: reconsider. Should be something faster
     */
    SimpleValues_t* values;

private slots:
    void updateThreadList();
};

class SimpleCounter : public QObject, public PerfCounterImpl
{
    Q_OBJECT
public:
    /**
     * Creator
     */ 
    static PerfCounterImpl* create();

    /**
     * Init counter for given process
     * and with given sampling rate.
     */
    void attach( DWORD pid, int msec);

    void start();

    void stop();

    void reset();

    void destroy();

    CounterValues* getValues();
public slots:
    /**
     * Slot to recieve worker thread results
     */
    void receiveValues( SimpleValues_t* val);

signals:
    /**
     * Signal to request counted values from worker thread.
     * Values are passed back through (@link valuesReady
     */
    void valuesRequest();

    /**
     * Signal to report that values are received
     */
    void valuesReady();
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
     * Thread handle to be attached to
     */
    HANDLE hProcess;

    /**
     * Values to return
     */
    CounterValuesImpl* values;

    /**
     * Info of simple counter
     */
    static const PerfCounterInfo info;

    /**
     * Perfrom info init and registration
     */
    static PerfCounterInfo doRegister();
};

}; // namespace win

}; // namespace perf
