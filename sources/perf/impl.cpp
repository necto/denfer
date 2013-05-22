/**
 * Implementation of common performance facilities
 */
/**
 * Copyright 2013 Denfer team
 */

#include "impl.hpp"

namespace perf
{

QString PerfCounterInfo::toString() const
{
    QString res("");
    res += "Name     : ";
    res += name + "\n";

    res += "UUID     : ";
    res += uuid.toString() + "\n";

    res += "Type     : ";
    switch ( type )
    {
    case COUNTER_PLAIN:
        res += "plain\n";
        break;
    case COUNTER_HIERARCHICAL:
        res += "hierarchical\n";
        break;
    default:
        Q_ASSERT(0);
    }

    res += "Provider : ";
    switch ( provider )
    {
    case PROVIDER_DENFER:
        res += "Denfer\n";
        break;
    default:
        Q_ASSERT(0);
    }

    return res;
}

}
