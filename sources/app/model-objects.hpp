/**
 * Declaration of objects used in model.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "../perf/iface.hpp"
#include "../proc/iface.hpp"
#include "../syminfo/iface.hpp"

namespace app
{

using perf::PerfCounter;
using proc::Process;

class SymbolObj : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString name READ getName WRITE setName)
    Q_PROPERTY( int length READ getLength WRITE setLength)
    Q_PROPERTY( int address READ getAddress WRITE setAddress)
public:
    SymbolObj();
    SymbolObj( const syminfo::Symbol* sym);
public slots:
    /* Sets/gets for properties */
    QString getName() const;
    void setName( QString _name);
    int getLength() const;
    void setLength( int _length);
    int getAddress() const;
    void setAddress( int _addr);
private:
    QString name;
    int length;
    int address;
};

class ProcessObj : public QObject 
{
    Q_OBJECT
    Q_PROPERTY( int id READ getId WRITE setId);
    Q_PROPERTY( int parent READ getParent WRITE setParent);
    Q_PROPERTY( QString name READ getName WRITE setName);
    Q_PROPERTY( QString file READ getFile WRITE setFile);
    Q_PROPERTY( QString user READ getUser WRITE setUser);
public: 
    ProcessObj();
    ProcessObj( const proc::Process* proc);
public slots:
    /* Sets/gets for properties */
    QString getName() const;
    void setName( QString _name);
    QString getUser() const;
    void setUser( QString _name);
    QString getFile() const;
    void setFile( QString _name);
    int getId() const;
    void setId(int _id);
    int getParent() const;
    void setParent( int _id);
private:
    int id;
    int parent;
    QString name;
    QString file;
    QString user;
};

class CounterObj : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int id READ getId WRITE setId)
public:
    CounterObj();
    CounterObj( perf::PerfCounter* cntr);
public slots:
    /* Sets/gets for properties */
    int getId() const;
    void setId( int _id);

    /* Attach counter to process */
    void attach( app::ProcessObj* proc);
private:
    int id;
    PerfCounter* counter;
};

class CounterInfoObj : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString name READ getName WRITE setName)
    Q_PROPERTY( QString uuid READ getUuid WRITE setUuid)
public:
    CounterInfoObj();
    CounterInfoObj( perf::PerfCounterInfo info);
public slots:
    /* Sets/gets for properties */
    QString getName() const;
    void setName( QString _name);
    QString getUuid() const;
    void setUuid( QString name);

    /* Create new counter of this type */
    app::CounterObj* create();
private:
    perf::PerfCounterInfo counter_info;
    QString name;
    QString uuid;
};

}
