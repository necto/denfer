/*
 * Implementation of console application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "console-interface.hpp"

namespace app
{

ConsoleInterface::ConsoleInterface( Model* m_, int argc, char** argv)
    :UserInterface( m_), qapp( argc, argv), m( m_)
{
    script.init( m);
}

ConsoleInterface::~ConsoleInterface()
{
}

int ConsoleInterface::execute()
{
    return script.repl();
}

}; //namespace app
