/**
 * Implementation of general functionality of
 * Performance counter class on Linux
 *
 * @author Denis Anisimov
 */
/**
 * Copyright 2013 Denfer team
 */

#include "perfcounter.hpp"

namespace perf
{

CounterValuesImpl::CounterValuesImpl() : simple_table( new SimpleTable_t)
{
}

SimpleTable_t* CounterValuesImpl::getSimpleTable()
{
    return simple_table;
}

void CounterValuesImpl::setSimpleTable( SimpleTable_t* table)
{
    simple_table = table;    
}

}; // namespace perf
