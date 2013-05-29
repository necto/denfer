/*
 * Implementation of SymbolTable class
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include <QProcess>
#include <QTextStream>
#include "iface.hpp"
#include "symbol-table.hpp"

namespace syminfo
{

const Symbol Symbol::undef = Symbol( ~0, 0);

SymbolTable::SymbolTable(QString filename)
{

//    QString command = "symtableparser.pl -f " + filename + " > temp.out";
    QString program = "symtableparser.pl";
    QStringList arguments;
    arguments << "-f " << filename;

    QProcess *parser = new QProcess();
    parser->start(program, arguments);
    parser->waitForFinished();

    QTextStream parser_out( parser->readAllStandardOutput());

    addr_t start_addr;
    addr_t addr_size;
    QString sym_name;
    while ( (parser_out >> start_addr >> addr_size >> sym_name).atEnd() )
    {   
        // add check for inline fuctions 
//        sym_set( insert( Symbol( start_addr, addr_size, sym_name)));   
    } 

}


SymbolTable::~SymbolTable()
{
}

void SymbolTable::insertSymbol( const Symbol& sym)
{
    symbols.push_back( sym);
    seg_root.insert( sym.address(), sym.length(), symbols.size()-1); 
    symname_map[sym.name()]=symbols.size()-1;
}

int SymbolTable::getNumberOfSymbols()
{
    return symbols.size();
}

SymbolList SymbolTable::getSymbolList()
{
    return symbols.toList();
}

Symbol SymbolTable::getSymbolByAddr( addr_t address)
{
    int sym_id = seg_root.findSymbol( address);
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
    return new SymbolTable( name);
}

bool SymbolTableIface::destroy( SymbolTableIface* table)
{
    delete (SymbolTable*) table;
    return true;
}

}; //namespace syminfo
