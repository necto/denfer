/**
 * Interface of performance facilities
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore\QMap>

namespace Perf
{

/**
 * Enum of possible performance counters
 */
enum PerfCountersEnum
{
    COUNTER_FUNC_CALLS,
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
    virtual ~PerfCounter() = 0;
};


typedef QMap<int, int> FunctionCallTable_t;

class FunctionCallCounter : public PerfCounter
{
public:
    /**
     * Instantiate actual function call implementation class.
     * @return reference to instance of implementation class
     */
    static FunctionCallCounter* create();
    
    /**
     * Return function calls counters
     * @param pointer to externally created table with function counters
     */
    static getValues(FunctionCallTable_t* func_table) = 0;
    
    /**
     * Virtual destructor to ensure proper deallocation
     * of implementation class.
     */
    virtual ~FunctionCallCounter() = 0;
};

}; // namespace Perf
