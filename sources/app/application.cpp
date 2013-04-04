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

    if ( mode == GUI)
        face = new GraphicalInterface( argc, argv);
    else
        face = new ConsoleInterface( argc, argv);
    core = BusinessLogicIface::create();
    face->setCore( core);
}

Application::~Application()
{
    BusinessLogicIface::destroy( core);
    delete face;
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
