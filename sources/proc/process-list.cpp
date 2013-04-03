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

QVector<QString> ProcessList::getProcessNames()
{
    QVector<QString> ret(10, QString("just another process"));
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
