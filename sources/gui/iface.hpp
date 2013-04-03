/**
 * Interface of profiler GUI
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once
#include <QtCore/QVector>
#include <QtCore/QString>

namespace gui
{

class MainWindowIface
{
public:
    virtual ~MainWindowIface() = 0;

    static MainWindowIface* create( int argc, char** argv);

    virtual void show() = 0;
    virtual void update( QVector<QString> procNames) = 0;
};

}; //namespace gui
