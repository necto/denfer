/**
 * Interface of profiler core
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

namespace core
{

class Application
{
public:
    virtual int execute() = 0;

    static Application* create( int argc, char** argv);
    static bool destroy( Application* ref);
};

}; //namespace core
