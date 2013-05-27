/**
 * The primary( and sole) implementation of gui BusinessLogicIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QtGui>
#include <QtCore/QMap>
#include "iface.hpp"
#include "proc/iface.hpp"
#include "perf/iface.hpp"
//#include <stdint.h>

namespace core
{

using proc::ProcessListIface;
using syminfo::SymbolTableIface;
using perf::PerfManager;

class EMA {
    double alpha_minus; // alpha value used to filter decreasing values
    double alpha_plus;  // alpha value used to filter increasing values 
    uint64_t prev;
    double value;
public:
    EMA() { alpha_minus = alpha_plus = 0.5; prev = 0; value = 0; }
    EMA(double amin, double amax) { alpha_minus = amin; alpha_plus = amax; prev = 0; value = 0; }
    
    double get_current() { return value; }
    double update(uint64_t val) { 
        double a;
        
        a = (val > prev) ? alpha_plus : alpha_minus;
        value = a * val + (1 - a) * value;
        
        prev = val;
        return value;
    }
    void setAlpha(double amin, double amax) { alpha_minus = amin; alpha_plus = amax; }
};

class BusinessLogic :public BusinessLogicIface
{
    ProcessListIface* procs;
    SymbolTableIface* symbols;
    PerfManager* perf_mgr;

    QMap<uint64_t, QString> counters;
    QMap<uint64_t, EMA> averages;
    
public:
    BusinessLogic();
    ~BusinessLogic();

    QList<perf::PerfCounterInfo> getCountersInfo();
    QList<QString> getCountersInfoStr();
    Process startProcess( QString name);
    QList<Process> getProcsSorted();
    QList<QString> getProcNames();
    bool attachToProcess( proc::procid process);
    bool attachToProcess( Process process);
    SymbolList getSymbols();


    /**
     * used to provide general counter information to here
     */
    virtual void setPerfCounterInfo(QVector<perf::PerfCounterInfo> *pci);

    /**
     * used to provide the individual counter values 
     */
    virtual void updatePerfCounterValue(uint64_t key, uint64_t value);
    
    /**
     * used to convey alpha values to averaging function
     */
    virtual void setAlphaValues(uint64_t key, double amin, double amax);
};

}; //namespace core
