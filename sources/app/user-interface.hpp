/**
 * The interface class for general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "model.hpp"

namespace app
{

class UserInterface
{
protected:
    Model* m;

public:
    UserInterface( Model* m_)
        :m( m_){};
    virtual ~UserInterface(){}

    virtual int execute() = 0;
};

}; //namespace app
