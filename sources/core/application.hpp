/**
 * The class -- realisation of Application iface.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "iface.hpp"

namespace core
{

class App :public Application
{
    QApplication qapp;
    QDialog *dialog;
    QLabel* l;

public:
    App( int argc, char** argv);
    ~App();
    int execute();
};

}; //namespace core
