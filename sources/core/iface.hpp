/**
 * Interface of profiler core
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtCore/QtGlobal>

namespace core
{

class X_EXPORT Application
{
public:
    virtual int execute() = 0;

    static Application* create( int argc, char** argv);
};

}; //namespace core
