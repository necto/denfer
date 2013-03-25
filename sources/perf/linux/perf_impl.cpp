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

using lin::PerfManagerImpl;

PerfManager* PerfManager::create()
{
    return (PerfManager*)( new PerfManagerImpl());
}

}; //namespace perf
