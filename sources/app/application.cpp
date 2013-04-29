/*
 * Implementation of the main application class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <string.h>
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
    
    m = new Model;

    if ( mode == GUI)
        face = new GraphicalInterface( m, argc, argv);
    else
        face = new ConsoleInterface( m, argc, argv);
    
    loadScripts();
}

Application::~Application()
{
    delete face;
    delete m;
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

void Application::loadScripts()
{
    const QList<QString> & files = args.getFiles();

    for ( QList<QString>::const_iterator i = files.begin();
          i != files.end(); ++i )
    {
        face->getScript()->interpretFile( *i);
    }
}

}; //namespace app
