/**
 * Interface of profiler core
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QString>
#include <QtCore/QVector>

namespace core
{

class X_EXPORT BusinessLogicIface
{
public:
    virtual QVector<QString> filterSmth( QVector<QString> procs) = 0;

    static BusinessLogicIface* create();
    static bool destroy( BusinessLogicIface* ref);
};

}; //namespace core
