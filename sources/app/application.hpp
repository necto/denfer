/**
 * The main class of the application
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "user-interface.hpp"
#include "core/iface.hpp"
#include "cl-arguments.hpp"
#include "model.hpp"

namespace app
{

using core::BusinessLogicIface;

class Application
{
    UserInterface* face;
    BusinessLogicIface* core;
    CLArguments args;
    Model* m;

    enum
    {
        CLI,
        GUI
    } mode;

public:
    Application( int argc, char** argv);
    virtual ~Application();

    int execute();

    void detectMode();
    void loadScripts();
};

}; //namespace app
