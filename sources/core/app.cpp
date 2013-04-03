/*
 * Implementation of application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include <QtGui>
#include "iface.hpp"
#include "app.hpp"

namespace core
{

App::App( int argc, char** argv)
    :qapp(argc, argv)
{
    procs = ProcessListIface::create();
    window = MainWindowIface::create( argc, argv);
    window->show();
}

App::~App()
{
    MainWindowIface::destroy( window);
    ProcessListIface::destroy( procs);
}

int App::execute()
{
    window->update( procs->getProcessNames());
    return qapp.exec();
}

Application* Application::create( int argc, char** argv)
{
    return new App(argc, argv);
}

bool Application::destroy( Application* ref)
{
    delete (App*)ref;
    return true;
}

}; //namespace core
