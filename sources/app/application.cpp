/*
 * Implementation of the main application class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <string.h>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include "application.hpp"
#include "console-interface.hpp"
#include "graphical-interface.hpp"

namespace app
{

Application::Application( int argc, char** argv)
    :args( argc, argv)
{
    detectMode();
    
    core = BusinessLogicIface::create();
    m = new Model( core);

    if ( mode == GUI)
        face = new GraphicalInterface( m, argc, argv);
    else
        face = new ConsoleInterface( m, argc, argv);
}

Application::~Application()
{
    delete face;
    delete m;
    BusinessLogicIface::destroy( core);
}

int Application::execute()
{
    return face->execute();
}

void Application::detectMode()
{
    if ( args.isConsole() )
        mode = CLI;
    else
        mode = GUI;
}

}; //namespace app
