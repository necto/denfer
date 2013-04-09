/**
 * Header file of simple performance counter on Linux.
 * This perf counter performs sampling of RIP from given process
 * with given time intervals.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "perf_impl.hpp"

namespace perf
{

namespace lin
{

class SimpleCounter : public PerfCounter
{
public:
    static const QUuid uuid;

};

}; // namespace lin

}; // namespace perf
