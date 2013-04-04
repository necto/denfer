/**
 * The CLI implementation of  general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "user-interface.hpp"

namespace app
{

class ConsoleInterface: public UserInterface
{
    QCoreApplication qapp;
public:
    ConsoleInterface( int argc, char** argv);
    ~ConsoleInterface();

    virtual int execute();
};

}; //namespace app
