/*
 * Implementation of console application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include "console-interface.hpp"

namespace app
{

ConsoleInterface::ConsoleInterface( int argc, char** argv)
    :qapp( argc, argv)
{
}

ConsoleInterface::~ConsoleInterface()
{
}

int ConsoleInterface::execute()
{
    return qapp.exec();
}

}; //namespace app
