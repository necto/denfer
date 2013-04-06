/*
 * Implementation of console application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <iostream>
#include <QtCore>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include "console-interface.hpp"

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

ConsoleInterface::ConsoleInterface( int argc, char** argv)
    :qapp( argc, argv)
{
}

ConsoleInterface::~ConsoleInterface()
{
}

void ConsoleInterface::repl()
{
    QTextStream in(stdin, QFile::ReadOnly);
    QTextStream out(stdout, QFile::WriteOnly);

    done = false;

    while ( !done)
    {
        out << "/*>*/ "; out.flush();
    
        QString code;
        QString line = in.readLine();

        code += line + "\n";

        while ( !script.canEvaluate( code))
        {
            out << "      "; out.flush();
            line = in.readLine();
            code += line + "\n";
        }

        out << script.evaluate(code).toString() <<endl;
    }
}

void ConsoleInterface::exit( int rez)
{
    done = true;
    result = rez;
}

QList<QString> ConsoleInterface::getProcNames()
{
    return core->getProcNames();
}

QList<Process> ConsoleInterface::getProcs()
{
    return core->getProcs();
}

int ConsoleInterface::execute()
{
    QScriptValue app = script.newQObject( this);
    script.globalObject().setProperty( "app", app);

    qScriptRegisterSequenceMetaType<QList<QString> > (&script);
    qScriptRegisterMetaType( &script, processToScriptVal, processFromScriptVal);
    qScriptRegisterSequenceMetaType<QList<proc::Process> > (&script);

    repl();

    return result;
}

}; //namespace app
