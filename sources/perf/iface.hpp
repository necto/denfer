/**
 * Interface of performance facilities
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QVector>

namespace Perf
{

/**
 * Enum of possible performance counters
 */
enum PerfCountersEnum
{
    COUNTER_FUNC_CALLS,
    COUNTER_SAMPLING,
    COUNTER_LAST
};

/**
 * Generic performance manager interface
 * @author Denis Anisimov
 */
class PerfManager
{
public:
    /**
     * Instantiate actual perf manager implementation class.
     * @return reference to instance of implementation class
     */
    static PerfManager* create();

    /**
     * Return available counters as a bitmask.
     * (see @link PerfCountersEnum)
     * @return bitmask
     */
    virtual int getAvailableCounters() = 0;

    /**
     * Virtual destructor to ensure proper deallocation
     * of implementation class.
     */
    virtual ~PerfManager() = 0;
};

/**
 * Generic performance counter interface
 * @author Denis Anisimov
 */
class PerfCounter
{
public:
    /**
     * Start measuring of perf data
     */
    virtual void start() = 0;

    /**
     * Stop measuring of perf data
     */
    virtual void stop() = 0;

    /**
     * Clear internally collected data
     */
    virtual void reset() = 0;

    /**
     * Virtual destructor to ensure proper deallocation
     * of implementation class.
     */
    virtual void destroy() = 0;
};


typedef unsigned long int Addr_t;
typedef unsigned long int Cnt_t;

typedef QVector<Addr_t, Cnt_t> SimpleTable_t;

class SimpleCounter : public PerfCounter
{
public:
    /**
     * Return function calls counters
     * @param pointer to externally created table with function counters
     */
    virtual void getValues( SimpleTable_t* func_table) = 0;
};

class FuncCallCounter : public SimpleCounter
{
public:
    /**
     * Instantiate actual function call implementation class.
     * @return reference to instance of implementation class
     */
    static FuncCallCounter* create();
};

typedef unsigned int Rate_t;

class SamplingCounter : public SimpleCounter
{
public:
    /**
     * Instantiate actual sampling counter implementation class.
     * @return reference to instance of implementation class
     */
    static SamplingCounter* create();

    /**
     * Set rate of sampling measurements.
     * @param rate of sampling in microseconds
     */
    virtual void setRate( Rate_t rate);
};

}; // namespace Perf
