/**
 * The CLI implementation of  general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include "user-interface.hpp"
#include "model.hpp"

namespace app
{

using proc::Process;

class ConsoleInterface: public UserInterface
{
    QCoreApplication qapp;

public:
    ConsoleInterface( Model* m_, int argc, char** argv);
    ~ConsoleInterface();

    virtual int execute();
    virtual void update(QList<QString> list);
};

}; //namespace app
