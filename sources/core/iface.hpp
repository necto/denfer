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

namespace core
{

using proc::Process;

class X_EXPORT BusinessLogicIface
{
public:
    virtual QList<QString> filterSmth( QList<QString> procs) = 0;
    virtual QList<QString> getProcNames() = 0;
    virtual QList<Process> getProcs() = 0;

    static BusinessLogicIface* create();
    static bool destroy( BusinessLogicIface* ref);
};

}; //namespace core
