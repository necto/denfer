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
}

BusinessLogic::~BusinessLogic()
{
}

QList<QString> BusinessLogic::filterSmth( QList<QString> names)
{
    return names;
}

QList<QString> BusinessLogic::getProcNames( QList<Process> procs)
{
    QList<QString> ret;
    
    for ( QList<Process>::const_iterator i = procs.begin();
          i != procs.end(); ++i )
        ret.append( i->name);

    return filterSmth( ret);
}

QList<QString> BusinessLogic::infosToStr( QVector<perf::PerfCounterInfo> infos)
{
    QList<QString> ret;
    
    for ( QVector<perf::PerfCounterInfo>::const_iterator i = infos.begin();
          i != infos.end(); ++i )
        ret.append( i->toString());

    return filterSmth( ret);
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
    (void)value_to_display;
}

}; //namespace core
