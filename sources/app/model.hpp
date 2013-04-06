/**
 * The model class - the representation of all information,
 * gathered by the profiler for user to work with.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QObject>
#include "core/iface.hpp"

class QScriptEngine;

namespace app
{

using core::BusinessLogicIface;
using proc::Process;

class Model: public QObject
{
    Q_OBJECT

    BusinessLogicIface* core;

public slots:
    QList<QString> getProcNames();
    QList<proc::Process> getProcs();

public:
    Model( BusinessLogicIface* core_);

    void registerSelf( QScriptEngine* eng);
};

}; //namespace app
