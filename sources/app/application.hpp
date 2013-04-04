/**
 * The main class of the application
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "gui/iface.hpp"
#include "proc/iface.hpp"
#include "core/iface.hpp"

class QCoreApplication;

namespace app
{

using gui::MainWindowIface;
using proc::ProcessListIface;
using core::BusinessLogicIface;

class Application
{
    QCoreApplication* qapp;
    MainWindowIface* window;
    ProcessListIface* procs;
    BusinessLogicIface* bl;

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
