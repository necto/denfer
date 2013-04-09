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
#include <QList>
#include <cstdint>
typedef void* addressType;
typedef uint64_t addr_t;
typedef uint64_t addrsize_t;

/**
 * Struct of symbol
 */
struct SymbolType
{
    /** Name of symbol */
    QString name;

    /** address */
    addr_t address;

    /** length */
    addrsize_t length;

    /** Debug info */
    debuginfo_t debug_info;

    /** List of parent functions */
    QList<SymbolType*> parents;
};

class SymbolTableInterface 
{
public:
    /**
     * Initialize and prepare SymbolTableInterface object
     * Returns prepared object
     */
    virtual static SymbolTableInterface create(QString) = 0;

    virtual bool destroy() = 0;

    /** 
     * Returns number of symbols
     */
    virtual int getNumberOfSymbols() = 0;

    virtual void getListOfSymbols(symbolType* symbols) = 0;

    virtual int getNumberOfAddresses() = 0;

    virtual void getListOfAddresses(addressType* address) = 0;

    virtual symbolType getSymbol(addressType address) = 0;

    virtual addressType getAddress(symbolType symbol) = 0;
}
