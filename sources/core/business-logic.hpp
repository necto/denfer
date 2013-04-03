/**
 * The primary( and sole) implementation of gui BusinessLogicIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtGui>
#include "iface.hpp"

namespace core
{

class BusinessLogic :public BusinessLogicIface
{
public:
    
    QVector<QString> filterSmth( QVector<QString> procs);
};

}; //namespace core
