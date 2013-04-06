/*
 * Implementation of ProcessList class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "iface.hpp"
#include "process-list.hpp"

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
