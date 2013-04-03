/**
 * Interface of process table
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtCore/QtGlobal>

namespace proc
{

class X_EXPORT ProcessListIface
{
public:
    virtual QVector<QString> getProcessNames() = 0;

    static ProcessListIface* create();
};

}; //namespace proc
