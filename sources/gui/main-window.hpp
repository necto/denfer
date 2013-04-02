/**
 * The primary( and sole) implementation of gui MainWindowIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtGui>
#include "iface.hpp"

namespace gui
{

class MainWindow : public MainWindowIface
{
    QDialog *dialog;
    QLabel* l;
public:
    MainWindow();
    ~MainWindow();

    void show();
    void update( QVector<QString> procNames);
};

}; //namespace gui
