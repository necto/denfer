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

void ConsoleInterface::interpretFile( QString fname)
{
    QFile file( fname);
    if ( file.open( QFile::ReadOnly | QFile::Text) )
    {
        QTextStream in(&file);
        QString code = "";
        int line = 0;

        while ( !in.atEnd() )
        {
            code += in.readLine() + "\n";
            ++line;
            if ( script.canEvaluate( code) )
            {
                QScriptValue val = script.evaluate( code, fname, line);
                if ( val.isError() )
                {
                    qDebug() << val.toString() <<"at " <<line <<" " <<fname;
                }
                code = "";
            }
        }
        file.close();
    }
    else
    {
        qDebug() << "Can't open file " << fname <<" : " << file.error() << "see QFile::FileError";
    }
}

void ConsoleInterface::load( QString name)
{
    QScriptContext* ctx = script.currentContext();
    ctx->setActivationObject( ctx->parentContext()->activationObject());
    ctx->setThisObject( ctx->parentContext()->thisObject());
    interpretFile( name);
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
