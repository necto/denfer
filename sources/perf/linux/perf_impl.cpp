/**
 * Implementation of performance manager class on Linux.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#include "../iface.hpp"
#include "perfmanager.hpp"

namespace Perf
{

PerfManager* PerfManager::create()
{
    return (PerfManager*)( new PerfManagerLinux);
}

}