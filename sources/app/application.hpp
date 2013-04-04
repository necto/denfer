/**
 * The main class of the application
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "user-interface.hpp"
#include "gui/iface.hpp"
#include "core/iface.hpp"

namespace app
{

using gui::MainWindowIface;
using core::BusinessLogicIface;

class Application
{
    UserInterface* face;
    BusinessLogicIface* core;

    enum
    {
        CLI,
        GUI
    } mode;

public:
    Application( int argc, char** argv);
    virtual ~Application();

    int execute();

    void detectMode( int argc, char** argv);
};

}; //namespace app
