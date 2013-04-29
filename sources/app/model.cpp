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
Q_DECLARE_METATYPE( proc::Process)
Q_DECLARE_METATYPE( QList<proc::Process>)
Q_DECLARE_METATYPE( syminfo::Symbol)
Q_DECLARE_METATYPE( QList<syminfo::Symbol>)

namespace app
{

QScriptValue processToScriptVal( QScriptEngine *engine, const proc::Process &p)
{
    QScriptValue obj = engine->newObject();
    obj.setProperty("name", p.name);
    obj.setProperty("id", p.id);
    return obj;
}

void processFromScriptVal( const QScriptValue &obj, proc::Process &p)
{
    p.name = obj.property("name").toString();
    p.id = obj.property("id").toInt32();
}

QScriptValue symbolToScriptVal( QScriptEngine *engine, const syminfo::Symbol& s)
{
    QScriptValue obj = engine->newObject();
    obj.setProperty( "name", s.name());
    obj.setProperty( "address", s.address());
    obj.setProperty( "length", s.length());
    return obj;
}

void symbolFromScriptVal( const QScriptValue &obj, syminfo::Symbol& s)
{
    s.setName( obj.property("name").toString());
    s.setAddress( obj.property("address").toInt32());
    s.setLength( obj.property("length").toInt32());
}

Model::Model()
{
    core = BusinessLogicIface::create();
    procs = ProcessListIface::create();
    symbols = SymbolTableIface::create("noname");
}

Model::~Model()
{
    BusinessLogicIface::destroy( core);
    ProcessListIface::destroy( procs);
    SymbolTableIface::destroy( symbols);
}

QList<QString> Model::getProcNames()
{
    return core->getProcNames( getProcs());
}

QList<Process> Model::getProcs()
{
    return procs->getProcesses();//core->getProcs();
}

QList<Symbol> Model::getProcFunctions()
{
    return symbols->getSymbolList().toList();
}

bool Model::attachToProcess( int id)
{
    (void)id;
    return false;
}

void Model::registerSelf( QScriptEngine* eng)
{
    qScriptRegisterSequenceMetaType<QList<QString> > (eng);
    qScriptRegisterMetaType( eng, processToScriptVal, processFromScriptVal);
    qScriptRegisterMetaType( eng, symbolToScriptVal, symbolFromScriptVal);
    qScriptRegisterSequenceMetaType<QList<proc::Process> > (eng);
    qScriptRegisterSequenceMetaType<QList<syminfo::Symbol> > (eng);

    QScriptValue data = eng->newQObject( this);
    eng->globalObject().setProperty( "m", data);

}

}; //namespace app
