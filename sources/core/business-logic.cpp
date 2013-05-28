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
    symbols = 0;
    perf_mgr = PerfManager::create();
}

BusinessLogic::~BusinessLogic()
{
    ProcessListIface::destroy( procs);
    if ( symbols)
        SymbolTableIface::destroy( symbols);
}

QList<perf::PerfCounterInfo> BusinessLogic::getCountersInfo()
{
    return perf_mgr->getAvailableCounters().toList();
}

QList<QString> BusinessLogic::getCountersInfoStr()
{
    QList<QString> ret;
    QList<perf::PerfCounterInfo> infos = getCountersInfo();
    
    for ( QList<perf::PerfCounterInfo>::const_iterator i = infos.begin();
          i != infos.end(); ++i )
        ret.append( i->toString());

    return ret;
}

Process BusinessLogic::startProcess( QString name)
{
    return procs->startProcess( name);
}

QList<Process> BusinessLogic::getProcsSorted()
{
    return procs->getProcesses();
}

QList<QString> BusinessLogic::getProcNames()
{
    QList<QString> ret;
    QList<Process> processes = procs->getProcesses();
    
    for ( QList<Process>::const_iterator i = processes.begin();
          i != processes.end(); ++i )
        ret.append( i->name);
    return ret;
}

bool BusinessLogic::attachToProcess( proc::procid process)
{
    return attachToProcess( procs->getProc( process));
}

bool BusinessLogic::attachToProcess( Process process)
{
    if ( symbols )
        SymbolTableIface::destroy( symbols);
    symbols = SymbolTableIface::create( process.file);
    return symbols != 0;
}

SymbolList BusinessLogic::getSymbols()
{
    if ( symbols )
        return symbols->getSymbolList();
    return SymbolList();
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
