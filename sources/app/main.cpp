/**
 * Main of Denfer profile
 */
/**
 * Copyright 2013 Denfer team
 */

#include <cstdlib>
#include "core/iface.hpp"

using namespace std;
using namespace core;

/*
 * 
 */
int main( int argc, char** argv)
{
    Application* app = Application::create( argc, argv);
    int ret = app->execute();
    delete app;
    return ret;
}

