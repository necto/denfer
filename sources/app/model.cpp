/*
 * Implementation of the model class, representing all data, user can
 * get from the system, and commands, ruling the profiler.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "model.hpp"
#include <QtCore>
#include <QList>
#include <QString>
#include <QtScript/QScriptEngine>

Q_DECLARE_METATYPE( QList<QString>)
Q_DECLARE_METATYPE( app::ProcessObj*)
Q_DECLARE_METATYPE( QList<app::ProcessObj*>)
Q_DECLARE_METATYPE( app::SymbolObj*)
Q_DECLARE_METATYPE( QList<app::SymbolObj*>)
Q_DECLARE_METATYPE( app::CounterInfoObj*)
Q_DECLARE_METATYPE( QList<app::CounterInfoObj*>)

namespace app
{

QScriptValue processObjToScriptVal( QScriptEngine *engine, ProcessObj* const &p)
{
    return engine->newQObject( p);
}

void processObjFromScriptVal( const QScriptValue &obj, ProcessObj* &p)
{
    p = qobject_cast<ProcessObj*>(obj.toQObject());
}

QScriptValue symbolObjToScriptVal( QScriptEngine *engine, SymbolObj* const &s)
{
    return engine->newQObject( s);
}

void symbolObjFromScriptVal( const QScriptValue &obj, SymbolObj* &s)
{
    s = qobject_cast<SymbolObj*>(obj.toQObject());
}

QScriptValue counterInfoObjToScriptVal( QScriptEngine *engine, CounterInfoObj* const &i)
{
    return engine->newQObject( i);
}

void counterInfoObjFromScriptVal( const QScriptValue &obj, CounterInfoObj* &i)
{
    i = qobject_cast<CounterInfoObj*>(obj.toQObject());
}


Model::Model()
{
    core = BusinessLogicIface::create();
    procs = ProcessListIface::create();
    symbols = SymbolTableIface::create("noname");
    perf_mgr = PerfManager::create();
}

Model::~Model()
{
    BusinessLogicIface::destroy( core);
    ProcessListIface::destroy( procs);
    SymbolTableIface::destroy( symbols);
}

QList<QString> Model::getProcNames()
{
    return core->getProcNames( procs->getProcesses());
}

QList<ProcessObj*> Model::getProcs()
{
    QList<proc::Process> procs_list = procs->getProcesses();
    QList<ProcessObj*> res;

    for ( QList<proc::Process>::const_iterator iter = procs_list.begin();
          iter != procs_list.end();
          iter++)
    {
        res.append( new ProcessObj( (const proc::Process*)&(*iter)));
    }

    return res;
}

QList<SymbolObj*> Model::getProcFunctions()
{
    QList<syminfo::Symbol> syms = symbols->getSymbolList().toList();
    QList<SymbolObj*> res;

    for ( QList<syminfo::Symbol>::const_iterator iter = syms.begin();
          iter != syms.end();
          iter++)
    {
        res.append( new SymbolObj( &(*iter)));
    }

    return res;
}

QList<CounterInfoObj*> Model::getCountersInfo()
{
    QVector<perf::PerfCounterInfo> infos = perf_mgr->getAvailableCounters();
    QList<CounterInfoObj*> res;
    
    for ( QVector<perf::PerfCounterInfo>::const_iterator iter = infos.begin();
          iter != infos.end();
          iter++)
    {
        res.append( new CounterInfoObj( &(*iter)));
    }

    return res;
}

QList<QString> Model::getCountersInfoStr()
{
    return core->infosToStr( perf_mgr->getAvailableCounters());
}

ProcessObj* Model::startProcess( QString name)
{
    proc::Process pr = procs->startProcess( name);
    const proc::Process* prp = &pr;
    return new ProcessObj( prp);
}

void Model::registerSelf( QScriptEngine* eng)
{
    qScriptRegisterMetaType( eng, processObjToScriptVal, processObjFromScriptVal);
    qScriptRegisterMetaType( eng, symbolObjToScriptVal, symbolObjFromScriptVal);
    qScriptRegisterMetaType( eng, counterInfoObjToScriptVal, counterInfoObjFromScriptVal);
    qScriptRegisterSequenceMetaType<QList<QString> > (eng);
    qScriptRegisterSequenceMetaType<QList<app::ProcessObj*> > (eng);
    qScriptRegisterSequenceMetaType<QList<app::SymbolObj*> > (eng);
    qScriptRegisterSequenceMetaType<QList<app::CounterInfoObj*> > (eng);

    QScriptValue data = eng->newQObject( this);
    eng->globalObject().setProperty( "m", data);

}

}; //namespace app
