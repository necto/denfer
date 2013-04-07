/*
 * Implementation of the command line arguments parsing facility.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <string.h>
#include <QFile>
#include "cl-arguments.hpp"

namespace app
{

CLArguments::CLArguments( int argc, char** argv)
{
    consolep = false;
    for ( int i = 0; i < argc; ++i )
    {
        if ( 0 == strcmp( "c", argv[i]) )
        {
            consolep = true;
        }

        if ( i > 0 )//Don't take the self into account
            rememberIfFile( argv[i]);
    }
}

void CLArguments::rememberIfFile( char* name)
{
    if ( QFile::exists( name) )
        files.append( name);
}

}; //namespace app
