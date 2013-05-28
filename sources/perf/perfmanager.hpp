/**
 * Header file for Performance manager class and 
 * Performance Counter Factory class on Linux
 * 
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "iface.hpp"

namespace perf
{

class PerfCounterImpl;

typedef PerfCounterImpl* (*creator_t)();

/**
 * Perf Counters Factory implementation on Linux
 */
class PerfCounterFactoryImpl : public PerfCounterFactory
{
public:
    /**
     * Get single instance
     */
    static PerfCounterFactoryImpl& getInstance();

    /**
     * Create  particular counter based on its guid
     * @params guid of counter
     * @return reference to instance of counter class
     */
    virtual PerfCounter* createCounter( QUuid uuid);

    /**
     * Register counter in current factory
     */
    PerfCounterFactory* registerCounter( QUuid uuid, creator_t t);
private:
    /**
     * Default constructor
     */
    PerfCounterFactoryImpl();

    /**
     * List of supported counters
     * Maps uuid to creator function
     */
    QMap<QUuid, creator_t> supported_counters;
};

/**
 * Implementation of performance manager for Linux
 * Singleton - there is no use in many managers
 */
class PerfManagerImpl : public PerfManager
{
public:
    /**
     * Get single instance
     */
    static PerfManagerImpl& getInstance();

    /**
     * Return available counters info.
     * (see @link PerfCounterInfo)
     * @return QVector of structures
     */
    virtual QVector<PerfCounterInfo> getAvailableCounters();

    /**
     * Virtual destructor to ensure proper deallocation
     * of implementation class.
     */
    virtual void destroy();

    /**
     * Register new counter
     */
    void registerCounter( PerfCounterInfo info);
private:
    /**
     * Default constructor
     */
    PerfManagerImpl();

    /**
     * Vector of available counters
     */
    QVector<PerfCounterInfo> counters;
};

}; // namespace perf
