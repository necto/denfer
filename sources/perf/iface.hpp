/**
 * Interface of performance facilities
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QVector>
#include <QtCore/QString>
#include <stdint.h>

namespace perf
{

/**
 * Enum of possible performance counter types
 */
enum PerfCounterType
{
    COUNTER_PLAIN,
    COUNTER_HIERARCHICAL,
    COUNTER_LAST
};


/**
 * Enum of perf counters providers
 */
enum PerfCounterProvider
{
    PROVIDER_DENFER,
    PROVIDER_LAST
};

class PerfCounter;

/**
 * Performance counter information
 */
struct PerfCounterInfo
{
    QString name;
    PerfCounterType type;
    PerfCounterProvider provider;
    uint64_t guid;
    PerfCounter* (*create)(uint64_t);
};

/**
 * Generic performance manager interface
 * 
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
     * Return available counters info.
     * (see @link PerfCounterInfo)
     * @return QVector of structures
     */
    virtual QVector<PerfCounterInfo> getAvailableCounters() = 0;

    /**
     * Virtual destructor to ensure proper deallocation
     * of implementation class.
     */
    virtual void destroy() = 0;
};

/**
 * Generic performance counter interface
 * 
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

/**
 * Definitions of plain counter data storage structures
 */
struct PlainRecord
{
    uint64_t key;
    uint64_t val;
};

typedef QVector<PlainRecord> SimpleTable_t;

/**
 * Plain counter interface.
 * 
 * Performs count of data in format: `integer key` - `integer value`.
 * @author Denis Anisimov
 */
class PlainCounter : public PerfCounter
{
public:
    /**
     * Return function calls counters
     * @param pointer to externally created table with function counters
     */
    virtual void getValues( SimpleTable_t* func_table) = 0;
};

}; // namespace perf
