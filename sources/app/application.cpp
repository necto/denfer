/*
 * Implementation of application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include <QtGui>
#include <QDebug>
#include "application.hpp"

namespace app
{

Application::Application( int argc, char** argv)
    :qapp(argc, argv)
{
    detectMode( qapp.arguments());
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
