/*
 * Implementation of application Interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QtCore>
#include <QtGui>
#include "iface.hpp"
#include "application.hpp"

namespace core
{

App::App( int argc, char** argv)
    :qapp(argc, argv)
{
    dialog = new QDialog;
    l = new QLabel( dialog);
    l->setText("<h1> This is the Denfer application</h1>");
    dialog->show();
}

App::~App()
{
    delete l;
    delete dialog;
}

int App::execute()
{
    return qapp.exec();
}

Application* Application::create( int argc, char** argv)
{
    return new App(argc, argv);
}

}; //namespace core
