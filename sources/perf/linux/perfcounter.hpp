/**
 * Header file for Performance counter class on Linux
 *
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "../iface.hpp"

namespace perf
{

namespace lin
{

class PerfCounterImpl : public PerfCounter
{
    Q_OBJECT
public:
    /**
     * Start measuring of perf data
     */
    virtual void start();

    /**
     * Stop measuring of perf data
     */
    virtual void stop();

    /**
     * Clear internally collected data
     */
    virtual void reset();

    /**
     * Get counted values
     * @return storage class.
     */
    virtual CounterValues* getValues();
signals:
    /**
     * Signal for worker thread to start counting
     */
    void start_signal();

    /**
     * Signal for worker thread to start counting
     */
    void stop_signal();

    /**
     * Signal for worker thread to start counting
     */
    void reset_signal();

};

}; // namespace lin

}; // namespace perf
