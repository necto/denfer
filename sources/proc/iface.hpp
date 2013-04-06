/**
 * Interface of process table
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QtGlobal>

namespace proc
{

struct X_EXPORT Process
{
    QString name;
    int id;
};

class X_EXPORT ProcessListIface
{
public:
    virtual QList<Process> getProcesses() = 0;

    static ProcessListIface* create();
    static bool destroy( ProcessListIface* ref);
};

}; //namespace proc
