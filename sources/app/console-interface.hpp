/**
 * The CLI implementation of  general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include <QtScript/QScriptEngine>
#include "user-interface.hpp"

namespace app
{

using proc::Process;

class ConsoleInterface: public QObject, public UserInterface
{
    Q_OBJECT

    QCoreApplication qapp;
    QScriptEngine script;

    bool done;
    int result;

    void repl();
    void interpretFile( QString fname);

public slots:
    void exit( int res = 0);
    QList<QString> getProcNames();
    QList<proc::Process> getProcs();
    void load( QString fname);

public:
    ConsoleInterface( int argc, char** argv);
    ~ConsoleInterface();

    virtual int execute();
};

}; //namespace app
