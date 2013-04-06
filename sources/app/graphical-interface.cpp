/*
 * Implementation of graphical application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include <QtGui>
#include "graphical-interface.hpp"

namespace app
{

GraphicalInterface::GraphicalInterface( BusinessLogicIface* core_, int argc, char** argv)
    :UserInterface( core_), qapp( argc, argv)
{
    window = MainWindowIface::create( argc, argv);
    window->showWindow();
}

GraphicalInterface::~GraphicalInterface()
{
    MainWindowIface::destroy( window);
}

int GraphicalInterface::execute()
{
    return qapp.exec();
}

}; //namespace app
