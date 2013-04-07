/**
 * The class, responsible for command line arguments parsing.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

namespace app
{

class CLArguments
{
    bool consolep;

public:
    CLArguments( int argc, char** argv);

    bool isConsole() const { return consolep; };
};

}; //namespace app
