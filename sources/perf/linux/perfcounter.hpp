/**
 * Header file for Performance counter class on Linux
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

class PerfCounterImpl : public PerfCounter, public QObject
{
    Q_OBJECT
    // Nothing to do here yet
};

}; // namespace lin

}; // namespace perf
