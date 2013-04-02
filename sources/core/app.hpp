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

namespace core
{

using gui::MainWindowIface;

class App :public Application
{
    QApplication qapp;
    MainWindowIface* window;

public:
    App( int argc, char** argv);
    ~App();

    int execute();
};

}; //namespace core
