/**
 * The interface class for general conceptin of user interface
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include "model.hpp"
#include "interpreter.hpp"

namespace app
{

class UserInterface
{
private:
    Interpreter* script;
    
protected:
    Model* m;

public:
    UserInterface( Model* m_);
    virtual ~UserInterface();

    Interpreter* getScript();

    virtual int execute() = 0;
    virtual void update(QList<QString> list) = 0;
};

}; //namespace app
