/**
 * The primary( and sole) implementation of gui BusinessLogicIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtGui>
#include "iface.hpp"
#include "proc/iface.hpp"

namespace core
{

using proc::ProcessListIface;

class BusinessLogic :public BusinessLogicIface
{
    ProcessListIface* procs;

public:
    BusinessLogic();
    ~BusinessLogic();
    
    QList<QString> filterSmth( QList<QString> procs);

    QList<QString> getProcNames();
};

}; //namespace core
