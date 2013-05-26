/*
 * Implementation of BusinessLogic class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "iface.hpp"
#include "business-logic.hpp"

namespace core
{

BusinessLogic::BusinessLogic()
{
    procs = ProcessListIface::create();
}

BusinessLogic::~BusinessLogic()
{
    ProcessListIface::destroy( procs);
}

QList<QString> BusinessLogic::filterSmth( QList<QString> names)
{
    return names;
}

QList<QString> BusinessLogic::getProcNames()
{
    QList<QString> ret;
    QList<Process> total = getProcs();
    
    for ( QList<Process>::const_iterator i = total.begin();
          i != total.end(); ++i )
        ret.append( i->name);

    return filterSmth( ret);
}

QList<Process> BusinessLogic::getProcs()
{
    return procs->getProcesses();
}

BusinessLogicIface* BusinessLogicIface::create()
{
    return new BusinessLogic;
}

bool BusinessLogicIface::destroy( BusinessLogicIface* ref)
{
    delete (BusinessLogic*)ref;
    return true;
}

void BusinessLogic::setPerfCounterInfo(QVector<perf::PerfCounterInfo> *pci) {
    QVector<perf::PerfCounterInfo>::const_iterator i;
    EMA e;
    
    counters.clear(); // clear QMap (delete all entries)
    averages.clear();
    for(i = pci->begin(); i != pci->end(); ++i) {
        counters[i->id] = i->name;
        averages[i->id] = e;
    }
} 

void BusinessLogic::setAlphaValues(uint64_t key, double amin, double amax) {
    averages[key].setAlpha(amin, amax);
    // averages.find(key)->setAlpha(amin, amax);
}

void BusinessLogic::updatePerfCounterValue(uint64_t key, uint64_t value) {
    QString name;
    double value_to_display;
    
    name = counters[key];
    value_to_display = averages[key].update(value); // this variable holds current average value for given perf counter 
}

}; //namespace core
