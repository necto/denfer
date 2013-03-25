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

#include "../iface.hpp"

namespace perf
{

namespace lin
{

/**
 * Perf Counters Factory implementation on Linux
 */
class PerfCounterFactoryImpl : public PerfCounterFactory
{
public:
    /**
     * Create  particular counter based on its guid
     * @params guid of counter
     * @return reference to instance of counter class
     */
    virtual PerfCounter* createCounter( uint64_t guid);
private:
    /**
     * Default constructor
     */
    PerfCounterFactoryImpl();
};

class PerfManagerImpl : public PerfManager
{
public:
    /**
     * Default constructor
     */
    PerfManagerImpl();
    
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
};

}; // namespace linux

}; // namespace perf
