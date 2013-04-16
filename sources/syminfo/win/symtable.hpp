#include "../impl.hpp"

using namespace syminfo;

class SymbolTableImpl: public SymbolTable
{
private:
    SymbolSet symbol_set;   

public:
    /** Construct Symbol Table */
    virtual static SymbolTableImpl create( QString path) = 0;

    virtual bool destroy() = 0;

    /** Returns number of symbols */
    virtual int getNumberOfSymbols() = 0;

    /** Returns reference to SymbolList */
    virtual SymbolSet& getSymbolList() = 0;

    /* Returns Symbol with specific address */
    virtual Symbol getSymbol(addr_t address) = 0;

    /* Returns address of symbol */
    virtual addr_t getAddress(Symbol symbol) = 0;

}
