/*
 * Implementation of ECMAScript interpreter, based on QtScriptEngine
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include "interpreter.hpp"

namespace app
{

Interpreter::Interpreter( Model* m)
    :model( m)
{
    QScriptValue app = script.newQObject( this);
    script.globalObject().setProperty( "app", app);
    
    model->registerSelf( &script);
    //TODO: find out who should delete these objects app, data?
}

Interpreter::~Interpreter()
{
}

int Interpreter::repl()
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
    return result;
}

void Interpreter::interpretFile( QString fname)
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

void Interpreter::load( QString name)
{
    QScriptContext* ctx = script.currentContext();
    ctx->setActivationObject( ctx->parentContext()->activationObject());
    ctx->setThisObject( ctx->parentContext()->thisObject());
    interpretFile( name);
}

void Interpreter::exit( int rez)
{
    done = true;
    result = rez;
}

}; //namespace app
