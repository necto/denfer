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
        tmp.push_back( Symbol( i*10, i, QString( "symbol %1").arg(i)));
    }
}

SymbolTable::~SymbolTable()
{
}

int SymbolTable::getNumberOfSymbols()
{
    return 10;
}

SymbolList& SymbolTable::getSymbolList()
{
    return tmp;
}

Symbol SymbolTable::getSymbol( addr_t address)
{
    for ( SymbolList::const_iterator i = tmp.begin(); i != tmp.end(); ++i )
        if ( i->contains( address) )
            return *i;
    return Symbol( 0, 0, "not found");
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
