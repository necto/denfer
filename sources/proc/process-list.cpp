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
        Process p = {i, 0, QString( "another process"), QString( "/usr/bin/id"), QString( "bourbaki")};
        ret.append( p);
    }
    return ret;
}

Process ProcessList::getProc( procid id)
{
    Process p = { id, 0, QString( "requested process"), QString( "/usr/bin/id"), QString( "bourbaki")};
    return p;
}

Process ProcessList::startProcess( QString cmd)
{
    Process p;
    qint64 id;
    p.name = cmd;

    if ( !QProcess::startDetached( cmd, QStringList(""), "", &id) )
    {
        qDebug() << "Cannot start process " << cmd;
    }
    
    p.id = id;
    p.parent = 0; //TODO : get the current process id
    p.user = "g-man"; //TODO: get the current user name
    p.file = cmd; //TODO
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
