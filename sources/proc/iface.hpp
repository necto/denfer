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

typedef int procid;// FIXME: change to cross-platform

struct X_EXPORT Process
{
    procid id; 
    procid parent;
    QString name;
    QString file;
    QString user;
};

class X_EXPORT ProcessListIface
{
public:
    virtual QList<Process> getProcesses() = 0;
    virtual Process startProcess( QString cmd) = 0;
    virtual Process getProc( procid id) = 0;

    static ProcessListIface* create();
    static bool destroy( ProcessListIface* ref);
};

}; //namespace proc
