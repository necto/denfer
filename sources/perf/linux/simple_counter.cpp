/**
 * Implementation of simple performance counter on Linux.
 * This perf counter performs sampling of RIP from given process
 * with given time intervals.
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#include "simple_counter.hpp"

namespace perf
{

namespace lin
{

const QUuid SimpleCounter::uuid = QUuid( "{00000000-0000-0000-0000-000000000001}");

}; // namespace lin

}; // namespace perf
