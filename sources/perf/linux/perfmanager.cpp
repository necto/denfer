/**
 * Implementation of performance manager class on Linux.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#include "../iface.hpp"

namespace Perf
{

PerfManager* PerfManager::create()
{
    return (PerfManager*)NULL;
}

QVector<PerfCounterInfo> PerfManager::getAvailableCounters()
{
    return QVector<PerfCounterInfo>();
}

void PerfManager::destroy()
{
}

}