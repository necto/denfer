/**
 * Implememntation of model objects
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#include "model-objects.hpp"

namespace app
{

SymbolObj::SymbolObj()
{
}

SymbolObj::SymbolObj( const syminfo::Symbol* sym)
{
    this->setProperty( "name", sym->name());
    this->setProperty( "address", (int)sym->address());
    this->setProperty( "length", (int)sym->length());
}

QString SymbolObj::getName() const
{
    return name;
}

void SymbolObj::setName( QString _name)
{
    name = _name;
}

int SymbolObj::getLength() const
{
    return length;
}

void SymbolObj::setLength( int _length)
{
    length = _length;
}

int SymbolObj::getAddress() const
{
    return address;
}

void SymbolObj::setAddress( int _address)
{
    address = _address;
}

ProcessObj::ProcessObj()
{
}

ProcessObj::ProcessObj( const proc::Process* proc)
{
    this->setProperty( "name", proc->name);
    this->setProperty( "id", proc->id);
    this->setProperty( "parent", proc->parent);
    this->setProperty( "file", proc->file);
    this->setProperty( "user", proc->user);
}

QString ProcessObj::getName() const
{
    return name;
}

void ProcessObj::setName( QString _name)
{
    name = _name;
}

QString ProcessObj::getFile() const
{
    return file;
}

void ProcessObj::setFile( QString _file)
{
    file = _file;
}

QString ProcessObj::getUser() const
{
    return user;
}

void ProcessObj::setUser( QString _user)
{
    user = _user;
}

int ProcessObj::getId() const
{
    return id;
}

void ProcessObj::setId( int _id)
{
    id = _id;
}

int ProcessObj::getParent() const
{
    return parent;
}

void ProcessObj::setParent( int _id)
{
    parent = _id;
}

CounterObj::CounterObj()
{
}

CounterObj::CounterObj( const perf::PerfCounter* cntr)
{
    counter = cntr;
}

int CounterObj::getId() const
{
    return id;
}

void CounterObj::setId( int _id)
{
    id = _id;
}

void CounterObj::attach( Process proc)
{
    (void)proc;
    //FIXME: add impl
}

CounterInfoObj::CounterInfoObj()
{
}

CounterInfoObj::CounterInfoObj( const perf::PerfCounterInfo* info)
{
    this->setProperty( "name", info->name);
    this->setProperty( "uuid", info->uuid.toString());
}

QString CounterInfoObj::getName() const
{
    return name;
}

void CounterInfoObj::setName( QString _name)
{
    name = _name;
}

QString CounterInfoObj::getUuid() const
{
    return uuid;
}

void CounterInfoObj::setUuid( QString _uuid)
{
    uuid = _uuid;
}

}
