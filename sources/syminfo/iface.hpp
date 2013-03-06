/**
 * Interface of symbolic info readers
 */
/**
 * authors: 
 *  Oleg Shimko 
 *  Robert Khasanov
 * 
 * Copyright 2013 Denfer team
 */

#pragma once

#include <QString>
typedef QString symbolType;
typedef void* addressType;

class SymbolTableInterface 
{
public:
    virtual bool initialize() = 0;
    virtual bool finalize() = 0;
    virtual int getNumberOfSymbols() = 0;
    virtual void getListOfSymbols(symbolType* symbols) = 0;
    virtual int getNumberOfAddresses() = 0;
    virtual void getListOfAddresses(addressType* address) = 0;
    virtual symbolType getSymbol(addressType address) = 0;
    virtual addressType getAddress(symbolType symbol) = 0;
}
