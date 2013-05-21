/*
 * Implementation of ProcessList class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "iface.hpp"
#include "process-list.hpp"
#include <QProcess>
#include <QDebug>

namespace proc
{

ProcessList::~ProcessList()
{
}

QList<Process> ProcessList::getProcesses()
{
    QList<Process> ret;

    for ( int i = 0; i < 10; ++i)
    {
        Process p = {QString( "another process"), i};
        ret.append( p);
    }
    return ret;
}

Process ProcessList::startProcess( QString name)
{
    Process p;
    qint64 id;
    p.name = name;

    if ( !QProcess::startDetached( name, QStringList(""), "", &id) )
    {
        qDebug() << "Cannot start process " << name;
    }
    
    p.id = id;
    return p;
}

ProcessListIface* ProcessListIface::create()
{
    return new ProcessList;
}

bool ProcessListIface::destroy( ProcessListIface* ref)
{
  delete (ProcessList*)ref;
  return true;
}

}; //namespace proc
