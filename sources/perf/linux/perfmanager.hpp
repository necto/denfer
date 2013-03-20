/**
 * Header file for Performance manager class on Linux
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

class PerfManagerLinux : public PerfManager
{
public:
    /**
     * Default constructor
     */
    PerfManagerLinux();
    
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

}; // namespace perf
