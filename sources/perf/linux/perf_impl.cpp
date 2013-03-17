/**
 * Implementation of performance counters on Linux.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#include "perf_impl.hpp"

namespace perf
{

PerfManager* PerfManager::create()
{
    return (PerfManager*)( new PerfManagerLinux());
}

}; //namespace perf
