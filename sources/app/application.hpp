/**
 * The main class of the application
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include <QApplication>
#include "gui/iface.hpp"
#include "proc/iface.hpp"
#include "core/iface.hpp"

namespace app
{

using gui::MainWindowIface;
using proc::ProcessListIface;

class Application
{
    QApplication qapp;
    MainWindowIface* window;
    ProcessListIface* procs;
    BusinessLogicIface* bl;

public:
    Application( int argc, char** argv);
    virtual ~Application();

    int execute();
};

}; //namespace app
