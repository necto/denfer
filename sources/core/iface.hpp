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
using perf::PerfCounterInfo;

class X_EXPORT BusinessLogicIface
{
public:
    virtual QList<QString> filterSmth( QList<QString> procs) = 0;
    virtual QList<QString> getProcNames( QList<Process> procs) = 0;
    virtual QList<QString> infosToStr( QVector<PerfCounterInfo> infos) = 0;

    static BusinessLogicIface* create();
    static bool destroy( BusinessLogicIface* ref);
};

}; //namespace core
