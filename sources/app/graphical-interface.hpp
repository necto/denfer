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

class GraphicalInterface : public QObject, public UserInterface
{
    Q_OBJECT

private:
    QApplication qapp;
    MainWindowIface* window;

protected:
    virtual void timerEvent(QTimerEvent *) {
        QList<QString> list = this->m->getProcNames();
        update(list);
    }

public:
    GraphicalInterface( Model* m_, int argc, char** argv);
    ~GraphicalInterface();

    virtual int execute();
    void update(QList<QString> list);
};

}; //namespace app
