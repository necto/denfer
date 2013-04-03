/*
 * Implementation of application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include <QtGui>
#include "application.hpp"

namespace app
{

Application::Application( int argc, char** argv)
    :qapp(argc, argv)
{
    detectMode( qapp.arguments());
    procs = ProcessListIface::create();
    bl = BusinessLogicIface::create();
    window = MainWindowIface::create( argc, argv);
    window->show();
}

Application::~Application()
{
    MainWindowIface::destroy( window);
    BusinessLogicIface::destroy( bl);
    ProcessListIface::destroy( procs);
}

int Application::execute()
{
    window->update( bl->filterSmth( procs->getProcessNames()));
    return qapp.exec();
}

void Application::detectMode( QStringList args)
{
    if ( -1 == args.indexOf( "c"))
        mode = GUI;
    else
        mode = CLI;
}

}; //namespace app
