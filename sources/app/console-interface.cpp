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

namespace app
{

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

int ConsoleInterface::execute()
{
    QScriptValue app = script.newQObject( this);
    script.globalObject().setProperty( "app", app);

    qScriptRegisterSequenceMetaType<QList<QString> > (&script);

    repl();

    return result;
}

}; //namespace app
