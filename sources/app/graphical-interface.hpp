/**
 * The GUI implementation of  general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QtCore>
#include <QtGui>
#include "user-interface.hpp"
#include "gui/iface.hpp"

namespace app
{

using gui::MainWindowIface;

class GraphicalInterface : public UserInterface
{
    QApplication qapp;
    MainWindowIface* window;
public:
    GraphicalInterface( int argc, char** argv);
    ~GraphicalInterface();

    virtual int execute();
};

}; //namespace app