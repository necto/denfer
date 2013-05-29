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
#include <set>

namespace syminfo
{

class Symbol;
typedef unsigned addr_t;
typedef size_t addrsize_t;
typedef QList<Symbol> SymbolList;
typedef QList<addr_t> AddrList;
    
struct Segment
{
    /** address */
    addr_t addr;
    /** length */
    addrsize_t len;
    /** index of symbol */
    int sym_ind;

    typedef std::set<Segment> SegmentSet;
    SegmentSet inner;

    Segment( addr_t a, addrsize_t l, int ind = -1): addr(a), len(l), sym_ind(ind) {}
    Segment(): addr(0), len(0), sym_ind(0) {}
    
    inline bool operator<(const Segment& S) const
    {
        return addr<S.addr;
    }

    inline bool contains( addr_t a) const
    {
       return addr <= a && a <= (addr+len); 
    }

    /**
     * Returns index of symbol.
     * If addr isn't existed, return -1
     */
    inline int findSymbol( addr_t a) const
    {
        if ( contains(a))
        {
            SegmentSet::iterator sit = inner.upper_bound( Segment(a,0));
            if ( sit == inner.begin())
                return sym_ind;
            
            sit--;
            int inner_ind = (*sit).findSymbol(a);
            if ( inner_ind == -1)
                return sym_ind;
            return inner_ind;
        }

        return -1;
    }

    /**
     * Insert segment to tree.
     * Return 0 - if segment is inserted correctly,
     * 1 - otherwise
     */
    inline int insert( addr_t a, addrsize_t l, int ind)
    {
        if ( contains(a) && contains(a+l))
        {
            SegmentSet::iterator sit = inner.upper_bound( Segment( a,0)), it, nit;
            if ( sit == inner.begin())
            {
                inner.insert( Segment(a,l,ind));
                return 0;
            }

            sit--;
            if ( (*sit).contains(a) && (*sit).contains(a+l))
            {
                Segment temp = *sit;
                inner.erase(sit);
                int ret = temp.insert( a, l, ind);
                inner.insert( temp);

                return ret;
            }
            
            Segment new_seg(a,l,ind);

            for ( it = inner.lower_bound(Segment(a,0)); 
                  it!= inner.upper_bound(Segment( a+l,0)); 
                  it=nit)
            {
                nit = it;
                nit++;
                new_seg.inner.insert( *it);
                inner.erase(it);
            }
            inner.insert(new_seg);
            return 0;
        }

        return 1;
    }
};

/**
 * Class Symbol
 */
class X_EXPORT Symbol
{
private:
    /** Name of symbol */
    QString name_;


    typedef QList<Segment> SegmentList;

    /** Original segment */
    Segment segm_;

    /** Inlined segments */
    SegmentList inl_;

public:
    inline QString name() const { return name_; }
    inline addr_t address() const { return segm_.addr;}
    inline addrsize_t length() const { return segm_.len;}
    inline void setName( const QString& n) { name_ = n; }
    inline void setAddress( addr_t a) { segm_.addr = a;}
    inline void setLength( addrsize_t l) { segm_.len = l;}
    inline void addSegment( addr_t a, addrsize_t l) { inl_.push_back(Segment( a,l));}
    inline bool contains( addr_t a) const
    { return segm_.contains( a); }

#if 0
    inline bool operator<(const Symbol& S) const
    {
        return address()<S.address();

    }
#endif

    inline bool operator==( const Symbol& S) const
    {
        return address()==S.address();
    }

    Symbol( const addr_t& addr, const addrsize_t& size, 
            QString name = QString(""))
    {
        setName( name);
        setAddress( addr);
        setLength( size);
    }

    Symbol() //Needed for scripting
        :name_(), segm_(), inl_() {}

    static const Symbol undef;
};

inline uint qHash( const Symbol&  s) {return s.address() % std::numeric_limits<uint>::max();}

class X_EXPORT SymbolTableIface
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
    virtual SymbolList getSymbolList() = 0;

    /* Returns Symbol with specific address */
    virtual Symbol getSymbolByAddr( addr_t address) = 0;

    /* Returns symbol with specific name */
    virtual Symbol getSymbolByName( QString name) = 0;
};

}
