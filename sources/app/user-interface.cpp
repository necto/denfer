/*
 * Implementation of some non-abstract facilities of the general user-interface class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "user-interface.hpp"

namespace app
{

UserInterface::UserInterface( Model* m_)
    :script( 0), m( m_)
{
}

UserInterface::~UserInterface()
{
    if ( script )
        delete script;
}

Interpreter* UserInterface::getScript()
{
    if ( script )
        return script;
    
    script = new Interpreter( m);
    return script;
}


}; //namespace app
