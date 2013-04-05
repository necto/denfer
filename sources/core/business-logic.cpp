/*
 * Implementation of BusinessLogic class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "iface.hpp"
#include "business-logic.hpp"

namespace core
{

BusinessLogic::BusinessLogic()
{
    procs = ProcessListIface::create();
}

BusinessLogic::~BusinessLogic()
{
    ProcessListIface::destroy( procs);
}

QList<QString> BusinessLogic::filterSmth( QList<QString> names)
{
    return names;
}

QList<QString> BusinessLogic::getProcNames()
{
    return filterSmth( procs->getProcessNames());
}

BusinessLogicIface* BusinessLogicIface::create()
{
    return new BusinessLogic;
}

bool BusinessLogicIface::destroy( BusinessLogicIface* ref)
{
    delete (BusinessLogic*)ref;
    return true;
}

}; //namespace core