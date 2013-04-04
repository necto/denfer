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

GraphicalInterface::GraphicalInterface( int argc, char** argv)
    :qapp( argc, argv)
{
    window = MainWindowIface::create( argc, argv);
    window->showWindow();
}

GraphicalInterface::~GraphicalInterface()
{
    delete window;
}

int GraphicalInterface::execute()
{
    return qapp.exec();
}

}; //namespace app
