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


namespace core
{

using proc::Process;

class X_EXPORT BusinessLogicIface
{
public:
    virtual QList<QString> filterSmth( QList<QString> procs) = 0;
    virtual QList<QString> getProcNames( QList<Process> procs) = 0;
    virtual QList<QString> infosToStr( QVector<perf::PerfCounterInfo> infos) = 0;

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
