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
{
    detectMode( argc, argv);
    
    core = BusinessLogicIface::create();

    if ( mode == GUI)
        face = new GraphicalInterface( core, argc, argv);
    else
        face = new ConsoleInterface( core, argc, argv);
}

Application::~Application()
{
    delete face;
    BusinessLogicIface::destroy( core);
}

int Application::execute()
{
    return face->execute();
}

void Application::detectMode( int argc, char** argv)
{
    mode = GUI;
    for (int i = 0; i < argc; ++i)
    {
        if ( 0 == strcmp( "c", argv[i]) )
        {
            mode = CLI;
            break;
        }
    }
}

}; //namespace app
