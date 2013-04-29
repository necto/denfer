/*
 * Implementation of SymbolTable class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "iface.hpp"
#include "symbol-table.hpp"

namespace syminfo
{

SymbolTable::SymbolTable()
{
    for ( int i = 0; i < 10; ++i)
    {
        tmp.insert( Symbol( i*10, i, "symbol"));
    }
}

SymbolTable::~SymbolTable()
{
}

int SymbolTable::getNumberOfSymbols()
{
    return 10;
}

SymbolSet& SymbolTable::getSymbolList()
{
    return tmp;
}

Symbol SymbolTable::getSymbol( addr_t address)
{
    return Symbol( address, 1, "sym");
}

addr_t SymbolTable::getAddress( Symbol symbol)
{
    return symbol.address();
}

SymbolTableIface* SymbolTableIface::create( QString name)
{
    (void)name;
    return new SymbolTable;
}

bool SymbolTableIface::destroy( SymbolTableIface* table)
{
    delete (SymbolTable*) table;
    return true;
}

}; //namespace syminfo
