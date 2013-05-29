/**
 * The mock implementation of SymbolTableIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include<QVector>
#include<QMap>
#include "iface.hpp"

namespace syminfo
{

class SymbolTable :public SymbolTableIface
{
    typedef QVector<Symbol> SymVec;
    typedef QMap<QString,int> NameIdMap;

    Segment seg_root;
    SymVec symbols;
    NameIdMap symname_map;

    void insertSymbol( const Symbol& sym);

public:
    SymbolTable( QString filename);
    ~SymbolTable();
    
    int getNumberOfSymbols();
    SymbolList getSymbolList();
    Symbol getSymbolByAddr( addr_t address);
    Symbol getSymbolByName( QString name);
};

}; //namespace syminfo
