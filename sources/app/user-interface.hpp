/**
 * The interface class for general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "core/iface.hpp"

namespace app
{

using core::BusinessLogicIface;

class UserInterface
{
protected:
    BusinessLogicIface* core;

public:
    UserInterface( BusinessLogicIface* core_)
        :core( core_){};
    virtual ~UserInterface(){}

    virtual int execute() = 0;
};

}; //namespace app
