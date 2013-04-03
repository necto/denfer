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
    static MainWindowIface* create( int argc, char** argv);
    static bool destroy( MainWindowIface* ref);

    virtual void show() = 0;
    virtual void update( QVector<QString> procNames) = 0;
};

}; //namespaceg gui
