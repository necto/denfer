/*
 * Implementation of graphical application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include <QtGui>
#include "graphical-interface.hpp"

namespace app
{

GraphicalInterface::GraphicalInterface( Model* m_, int argc, char** argv)
    :UserInterface( m_), qapp( argc, argv)
{
    window = MainWindowIface::create( argc, argv);
    window->showWindow();

    startTimer(1000);
}

GraphicalInterface::~GraphicalInterface()
{
    MainWindowIface::destroy( window);
}

int GraphicalInterface::execute()
{
    return qapp.exec();
}

void GraphicalInterface::update(QList<QString> list)
{
    this->window->updateWindow(list);
}

}; //namespace app
