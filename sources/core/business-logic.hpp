/**
 * The primary( and sole) implementation of gui BusinessLogicIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "iface.hpp"

namespace core
{

class BusinessLogic :public BusinessLogicIface
{

public:
    BusinessLogic();
    ~BusinessLogic();
    
    QList<QString> filterSmth( QList<QString> procs);

    QList<QString> getProcNames( QList<Process> procs);
};

}; //namespace core
