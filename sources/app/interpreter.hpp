/**
 * The interpreter class incapsulating QtScript engine
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include <QtScript/QScriptEngine>
#include "model.hpp"

namespace app
{

class Interpreter: public QObject
{
    Q_OBJECT

    QScriptEngine script;
    Model* model;

    bool done;
    int result;

public slots:
    void exit( int res = 0);
    void load( QString fname);

public:
    Interpreter();
    ~Interpreter();

    void init( Model* m);

    int repl();
    void interpretFile( QString fname);
};

}; //namespace app
