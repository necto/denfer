/**
 * The model class - the representation of all information,
 * gathered by the profiler for user to work with.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QObject>
#include "core/iface.hpp"
#include "syminfo/iface.hpp"
#include "perf/iface.hpp"

class QScriptEngine;

namespace app
{

using core::BusinessLogicIface;
using proc::ProcessListIface;
using proc::Process;
using syminfo::SymbolTableIface;
using syminfo::Symbol;
using syminfo::SymbolSet;
using perf::PerfManager;
using perf::PerfCounterInfo;

class Model: public QObject
{
    Q_OBJECT

    BusinessLogicIface* core;
    ProcessListIface* procs;
    SymbolTableIface* symbols;
    PerfManager* perf_mgr; 

public slots:
    QList<QString> getProcNames();
    QList<proc::Process> getProcs();
    QList<syminfo::Symbol> getProcFunctions();
    bool attachToProcess( proc::Process);
    
    QVector<perf::PerfCounterInfo> getCountersInfo();
    QList<QString> getCountersInfoStr();

    proc::Process startProcess( QString name);

public:
    Model();
    ~Model();

    void registerSelf( QScriptEngine* eng);
};

}; //namespace app
