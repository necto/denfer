/**
 * The mock implementation of SymbolTableIface
 */
/**
 * Copyright 2013 Denfer team
 */

#pragma once

#include "iface.hpp"

namespace syminfo
{

class SymbolTable :public SymbolTableIface
{
    SymbolList tmp;

public:
    SymbolTable();
    ~SymbolTable();
    
    int getNumberOfSymbols();
    SymbolList& getSymbolList();
    Symbol getSymbol( addr_t address);
    addr_t getAddress( Symbol symbol);
};

}; //namespace syminfo
