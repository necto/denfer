/**
 * Interface of profiler core
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtCore/QList>
#include "proc/iface.hpp"
#include "perf/iface.hpp"
#include "syminfo/iface.hpp"

namespace core
{

using proc::Process;
using syminfo::SymbolList;

class X_EXPORT BusinessLogicIface
{
public:

    virtual QList<perf::PerfCounterInfo> getCountersInfo() = 0;
    virtual QList<QString> getCountersInfoStr() = 0;
    virtual Process startProcess( QString name) = 0;
    virtual QList<Process> getProcsSorted() = 0;
    virtual QList<QString> getProcNames() = 0;
    virtual bool attachToProcess( proc::procid process) = 0;
    virtual bool attachToProcess( Process process) = 0;
    virtual SymbolList getSymbols() = 0;

    static BusinessLogicIface* create();
    static bool destroy( BusinessLogicIface* ref);

    /**
     * used to provide general counter information to here
     */
    virtual void setPerfCounterInfo(QVector<perf::PerfCounterInfo> *pci) = 0;

    /**
     * used to provide the individual counter values 
     */
    virtual void updatePerfCounterValue(uint64_t key, uint64_t value) = 0;

    /**
     * used to convey alpha values to averaging function
     */
    virtual void setAlphaValues(uint64_t key, double amin, double amax) = 0;
};

}; //namespace core
