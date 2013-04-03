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

QVector<QString> BusinessLogic::filterSmth( QVector<QString> procs)
{
    return procs;
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
