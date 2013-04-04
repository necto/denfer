/**
 * The interface class for general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

namespace app
{

class UserInterface
{
public:
    virtual ~UserInterface(){};

    virtual int execute() = 0;
};

}; //namespace app
