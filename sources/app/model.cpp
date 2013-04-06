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

Q_DECLARE_METATYPE(QList<QString>)
Q_DECLARE_METATYPE(proc::Process)
Q_DECLARE_METATYPE(QList<proc::Process>)

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

Model::Model( BusinessLogicIface* core_)
    :core( core_)
{
}

QList<QString> Model::getProcNames()
{
    return core->getProcNames();
}

QList<Process> Model::getProcs()
{
    return core->getProcs();
}

void Model::registerSelf( QScriptEngine* eng)
{
    qScriptRegisterSequenceMetaType<QList<QString> > (eng);
    qScriptRegisterMetaType( eng, processToScriptVal, processFromScriptVal);
    qScriptRegisterSequenceMetaType<QList<proc::Process> > (eng);

    QScriptValue data = eng->newQObject( this);
    eng->globalObject().setProperty( "m", data);

}

}; //namespace app
