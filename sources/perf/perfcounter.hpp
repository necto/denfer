/**
 * Header file for Performance counter class on Linux
 *
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "iface.hpp"

namespace perf
{

class PerfCounterImpl : public PerfCounter
{
    // Nothing to do here yet
public:
    /**
     * Create new perf counter
     */
    static PerfCounterImpl* create();
};

class CounterValuesImpl : public CounterValues
{
private:
    /**
     * Internal storage
     */
    SimpleTable_t* simple_table;
public:
    /**
     * Default constructor
     */
    CounterValuesImpl();

    /**
     * Get values as simple table
     * @return pointer to simple key-value data storage
     */
    virtual SimpleTable_t* getSimpleTable();

    /**
     * Set simple table storage from map
     */
    virtual void setSimpleTable( SimpleTable_t* table);
};

}; // namespace perf
