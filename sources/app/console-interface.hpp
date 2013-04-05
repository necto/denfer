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

class ConsoleInterface: public QObject, public UserInterface
{
    Q_OBJECT

    QCoreApplication qapp;
    QScriptEngine script;

    bool done;
    int result;

    void repl();

public slots:
    void exit( int res = 0);
    QList<QString> getProcNames();

public:
    ConsoleInterface( int argc, char** argv);
    ~ConsoleInterface();

    virtual int execute();
};

}; //namespace app
