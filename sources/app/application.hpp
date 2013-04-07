/**
 * The main class of the application
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "user-interface.hpp"
#include "core/iface.hpp"
#include "cl-arguments.hpp"
#include "model.hpp"

namespace app
{

using core::BusinessLogicIface;

class Application : public QObject
{
    Q_OBJECT

    UserInterface* face;
    BusinessLogicIface* core;
    CLArguments args;
    Model* m;

    enum
    {
        CLI,
        GUI
    } mode;

protected:
    virtual void timerEvent(QTimerEvent *) {
        QList<QString> list = core->getProcNames();
        this->face->update(list);
    }

public:
    Application( int argc, char** argv);
    virtual ~Application();

    int execute();

    void detectMode();
    void loadScripts();
};

}; //namespace app
