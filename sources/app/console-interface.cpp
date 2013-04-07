/*
 * Implementation of console application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "console-interface.hpp"
#include "interpreter.hpp"

namespace app
{

ConsoleInterface::ConsoleInterface( Model* m_, int argc, char** argv)
    :UserInterface( m_), qapp( argc, argv)
{
}

ConsoleInterface::~ConsoleInterface()
{
}

int ConsoleInterface::execute()
{
    return getScript()->repl();
}

void ConsoleInterface::update(QList<QString> list)
{
    // dummy
}

}; //namespace app
