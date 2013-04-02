/**
 * The class -- realisation of Application iface.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include "iface.hpp"
#include "gui/iface.hpp"
#include "proc/iface.hpp"

namespace core
{

using gui::MainWindowIface;
using proc::ProcessListIface;

class App :public Application
{
    QApplication qapp;
    MainWindowIface* window;
    ProcessListIface* procs;

public:
    App( int argc, char** argv);
    ~App();

    int execute();
};

}; //namespace core
