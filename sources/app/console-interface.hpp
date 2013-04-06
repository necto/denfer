/**
 * The CLI implementation of  general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include "user-interface.hpp"
#include "interpreter.hpp"
#include "model.hpp"

namespace app
{

using proc::Process;

class ConsoleInterface: public UserInterface
{
    QCoreApplication qapp;
    Interpreter script;
    Model m;

public:
    ConsoleInterface( BusinessLogicIface* core_, int argc, char** argv);
    ~ConsoleInterface();

    virtual int execute();
};

}; //namespace app
