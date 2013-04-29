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

class QScriptEngine;

namespace app
{

using core::BusinessLogicIface;
using proc::ProcessListIface;
using proc::Process;
using syminfo::SymbolTableIface;
using syminfo::Symbol;
using syminfo::SymbolSet;

class Model: public QObject
{
    Q_OBJECT

    BusinessLogicIface* core;
    ProcessListIface* procs;
    SymbolTableIface* symbols;

public slots:
    QList<QString> getProcNames();
    QList<proc::Process> getProcs();
    QList<syminfo::Symbol> getProcFunctions();
    bool attachToProcess( int id);
    
    /*
      getCounters
      getCounterName
    */

public:
    Model();
    ~Model();

    void registerSelf( QScriptEngine* eng);
};

}; //namespace app
