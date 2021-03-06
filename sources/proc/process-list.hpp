/**
 * The primary( and sole) implementation of ProcessListIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "iface.hpp"

namespace proc
{

class ProcessList : public ProcessListIface
{
public:
    virtual ~ProcessList();

    QList<Process> getProcesses();
    Process startProcess( QString cmd);
    Process getProc( procid id);
};

}; //namespace proc
