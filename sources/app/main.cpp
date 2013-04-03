/**
 * Main of Denfer profile
 */
/**
 * Copyright 2013 Denfer team
 */

#include <cstdlib>
#include "application.hpp"

using namespace std;
using namespace app;

/*
 * 
 */
int main( int argc, char** argv)
{
    Application* app = new Application(argc, argv);
    int ret = app->execute();
    delete app;
    return ret;
}

