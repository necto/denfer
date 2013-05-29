/*
 * Implementation of SymbolTable class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QProcess>
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

SymbolTable::SymbolTable(QString filename)
{

    QString command = "symtableparser.pl -f " + filename " > temp.out";
#if 0
    QString program = "symtableparser.pl";
    QStringList arguments;
    arguments << "-f " << filename;

    QProcess *parser = new QProcess();
#endif
    int status = system(command); // QProcess 
    if ( status != 0)
    {
        // ERROR
    }

    ifstream infile("temp.out");
    addr_t start_addr;
    addr_t addr_size;
    QString sym_name;
    while ( infile >> start_addr >> addr_size >> sym_name)
    {   
        // add check for inline fuctions 
        sym_set( insert( Symbol( start_addr, addr_size, sym_name)));   
    } 

}


SymbolTable::~SymbolTable()
{
}

void SymbolTable::insertSymbol( Symbol sym)
{
    symbols.push_back( sym);
    root_seg.insert( sym.address(), sym.length(), symbols.size()-1); 
    symname_map[sym.name()]=symbols.size()-1;
}

int SymbolTable::getNumberOfSymbols()
{
    return symbols.size();
}

SymbolList& SymbolTable::getSymbolList()
{
    return symbols.toList();
}

Symbol SymbolTable::getSymbolByAddr( addr_t address)
{
    int sym_id = root_seg.findSymbol( address);
    if ( sym_id == -1 ) 
        return Symbol::undef;
    return symbols[sym_id];
}

Symbol SymbolTable::getSymbolByName( QString name)
{
    if ( symname_map.contains( name))
    {
        return symbols[symname_map[name]];
    }
    return Symbol::undef;
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
