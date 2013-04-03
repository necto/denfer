/**
 * Interface of process table
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QString>
#include <QtCore/QVector>

namespace proc
{

class ProcessListIface
{
public:
    virtual QVector<QString> getProcessNames() = 0;

    static ProcessListIface* create();
    static bool destroy( ProcessListIface* ref);
};

}; //namespace proc
