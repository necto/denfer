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

using lin::PerfManagerImpl;

PerfManager* PerfManager::create()
{
    return (PerfManager*)( &PerfManagerImpl::getInstance());
}

namespace lin
{

PerfCounterFactoryImpl& PerfCounterFactoryImpl::getInstance()
{
    static PerfCounterFactoryImpl instance;
    return instance;
}

PerfCounterFactoryImpl::PerfCounterFactoryImpl()
{
    // Not yet implemented
}

PerfCounterFactory* PerfCounterFactoryImpl::registerCounter( QUuid uuid, creator_t creator)
{
    supported_counters.insert( uuid, creator);
    return (PerfCounterFactory*)&PerfCounterFactoryImpl::getInstance();
}

PerfCounter* PerfCounterFactoryImpl::createCounter( QUuid uuid)
{
    Q_ASSERT( supported_counters.find( uuid) != supported_counters.end() );
    return (PerfCounter*)(supported_counters.value( uuid))();
}

PerfManagerImpl& PerfManagerImpl::getInstance()
{
    static PerfManagerImpl instance;
    return instance;
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
    return counters;
}

void PerfManagerImpl::registerCounter( PerfCounterInfo info)
{
    counters.push_back(info);
}

}; // namespace linux

}; // namespace perf
