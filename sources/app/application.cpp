/*
 * Implementation of application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <string.h>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include "application.hpp"

namespace app
{

Application::Application( int argc, char** argv)
{
    detectMode( argc, argv);
    
    if ( mode == GUI)
        qapp = new QApplication( argc, argv);
    else
        qapp = new QCoreApplication( argc, argv);

    procs = ProcessListIface::create();
    bl = BusinessLogicIface::create();
    if ( mode == GUI)
    {
        window = MainWindowIface::create( argc, argv);
        window->showWindow();
    }
}

Application::~Application()
{
    if ( mode == GUI)
    {
        MainWindowIface::destroy( window);
    }
    BusinessLogicIface::destroy( bl);
    ProcessListIface::destroy( procs);
    
    delete qapp;
}

int Application::execute()
{
    QVector<QString> process_names = bl->filterSmth( procs->getProcessNames());
    if ( mode == GUI)
    {
        // Not yet implemented
    } else
    {
        Q_FOREACH( const QString& name, process_names)
            qDebug() << name <<"\n";
    }
    return qapp->exec();
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
