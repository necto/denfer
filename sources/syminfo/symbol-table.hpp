/**
 * The mock implementation of SymbolTableIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include<QVector>
#include "iface.hpp"

namespace syminfo
{

class SymbolTable :public SymbolTableIface
{
    typedef QVector<Symbol> SymVec;

    Segment seg_root;

    SymVec symbols;

    void insertSymbol( const Symbol& sym);

public:
    SymbolTable();
    ~SymbolTable();
    
    int getNumberOfSymbols();
    SymbolSet& getSymbolList();
    Symbol getSymbol( addr_t address);
    addr_t getAddress( Symbol symbol);
};

}; //namespace syminfo
