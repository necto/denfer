/**
 * Implementation of performance manager class on Linux.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */
 
#include "perfmanager.hpp"

namespace perf
{

namespace lin
{

PerfCounterFactoryImpl::PerfCounterFactoryImpl()
{
    // Not yet implemented
}

PerfCounter* PerfCounterFactoryImpl::createCounter( uint64_t uuid)
{
    // Not yet implemented
    return (PerfCounter*)( NULL);
}

PerfManagerImpl::PerfManagerImpl()
{
    // Not yet implemented
}

void PerfManagerImpl::destroy()
{
    // Not yet implemented
}

QVector<PerfCounterInfo> PerfManagerImpl::getAvailableCounters()
{
    // Not yet implemented
    return QVector<PerfCounterInfo>();
}

}; // namespace linux

}; // namespace perf
