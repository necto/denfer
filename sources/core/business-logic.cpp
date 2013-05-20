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
}

BusinessLogic::~BusinessLogic()
{
}

QList<QString> BusinessLogic::filterSmth( QList<QString> names)
{
    return names;
}

QList<QString> BusinessLogic::getProcNames( QList<Process> procs)
{
    QList<QString> ret;
    
    for ( QList<Process>::const_iterator i = procs.begin();
          i != procs.end(); ++i )
        ret.append( i->name);

    return filterSmth( ret);
}

QList<QString> BusinessLogic::infosToStr( QVector<PerfCounterInfo> infos)
{
    QList<QString> ret;
    
    for ( QVector<PerfCounterInfo>::const_iterator i = infos.begin();
          i != infos.end(); ++i )
        ret.append( i->toString());

    return filterSmth( ret);
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
