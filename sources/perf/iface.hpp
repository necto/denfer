/**
 * Interface of performance facilities
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore>
#include <QtCore/QVector>
#include <QtCore/QString>
#include <QtCore/QUuid>
//#include <stdint.h>

typedef unsigned long long uint64_t;

namespace perf
{

class PerfCounter;

/**
 *  Genereic performance counter factory interface.
 */
class X_EXPORT PerfCounterFactory
{
public:
    /**
     * Create particular counter based on its guid
     * @params guid of counter
     * @return reference to instance of counter class
     */
    virtual PerfCounter* createCounter( QUuid uuid) = 0;
};

/**
 * Enum of possible performance counter types
 */
enum X_EXPORT PerfCounterType
{
    COUNTER_PLAIN,
    COUNTER_HIERARCHICAL,
    COUNTER_LAST
};


/**
 * Enum of perf counters providers
 */
enum X_EXPORT PerfCounterProvider
{
    PROVIDER_DENFER,
    PROVIDER_LAST
};

/**
 * Performance counter information
 */
struct X_EXPORT PerfCounterInfo
{
    QString name;
    PerfCounterType type;
    PerfCounterProvider provider;
    QUuid uuid;
    uint64_t id;
    PerfCounterFactory* factory;

    /**
     * Convert structure to printable view
     */
    QString toString() const;
};

/**
 * Generic performance manager interface
 * 
 * @author Denis Anisimov
 */
class X_EXPORT PerfManager
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
 * Definitions of plain counter data storage structures
 */
struct X_EXPORT PlainRecord
{
    quint64 key;
    quint64 val;
};

typedef QVector<PlainRecord> SimpleTable_t;

/**
 * Storage class for different types of possible values
 */
class X_EXPORT CounterValues
{
    /**
     * Get values as simple table
     * @return pointer to simple key-value data storage
     */
    virtual SimpleTable_t* getSimpleTable() = 0;
};

/**
 * Generic performance counter interface
 * 
 * @author Denis Anisimov
 */
class X_EXPORT PerfCounter
{
public:
    /**
     * Attach counter to process with given pid
     */
    virtual void attach( pid_t pid) = 0;

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
     * Get counted values
     * @return storage class.
     */
    virtual CounterValues* getValues() = 0;

    /**
     * Virtual destructor to ensure proper deallocation
     * of implementation class.
     */
    virtual void destroy() = 0;
};


}; // namespace perf
