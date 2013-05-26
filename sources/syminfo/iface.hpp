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

#include <limits>
#include <QString>
#include <QList>
#include <QSet>

namespace syminfo
{

class Symbol;
typedef int addr_t;
typedef size_t addrsize_t;
typedef QList<Symbol*> SymbolList;

/**
 * Class Symbol
 */
class Symbol
{
private:
    /** Name of symbol */
    QString name_;

    /** address */
    addr_t address_;

    /** length */
    addrsize_t length_;

#if 0
    /** Debug info */
    DebugInfo debug_info_;

    /** List of parent functions */
    SymbolList parents_;
#endif
public:
    inline QString name() const { return name_; }
    inline addr_t address() const { return address_;}
    inline addrsize_t length() const { return length_;}
    inline void setName( const QString& n) { name_ = n; }
    inline void setAddress( addr_t a) { address_ = a;}
    inline void setLength( addrsize_t l) { length_ = l;}
    inline bool contains( addr_t a) const
    { return address_ < a && a < (address_ + length_); }
#if 0
    inline DebugInfo debug_info() const { return debug_info_;}
    inline const SymbolList& parents() const { return parents_;} 
#endif 

    inline bool operator<(const Symbol& S) const
    {
        return address_<S.address();

    }

    inline bool operator==( const Symbol& S) const
    {
        return address_==S.address();
    }

    Symbol( const addr_t& addr, const addrsize_t& size, 
            QString name = QString(""))
    {
        address_ = addr;
        length_ = size;
        name_ = name;
    }

    Symbol() //Needed for scripting
        :name_(), address_(), length_() {}
};

inline uint qHash( const Symbol&  s) {return s.address() % std::numeric_limits<uint>::max();}

typedef QSet<Symbol> SymbolSet;

class SymbolTableIface
{
public:
    /**
     * Initialize and prepare SymbolTableInterface object
     * Returns prepared object
     */
    static SymbolTableIface* create(QString);

    static bool destroy( SymbolTableIface*);

    /** Returns number of symbols */
    virtual int getNumberOfSymbols() = 0;

    /** Returns reference to SymbolList */
    virtual SymbolSet& getSymbolList() = 0;

    /* Returns Symbol with specific address */
    virtual Symbol getSymbol( addr_t address) = 0;

    /* Returns address of symbol */
    virtual addr_t getAddress( Symbol symbol) = 0;
};

}
