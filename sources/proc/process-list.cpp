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

QList<QString> ProcessList::getProcessNames()
{
    QList<QString> ret;
    for (int i = 0; i < 10; ++i)
        ret.append(QString("just another process"));
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
