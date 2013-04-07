/**
 * The class, responsible for command line arguments parsing.
 */
/**
 * Copyright 2013 Denfer team. See http://github.com/necto/denfer
 */

#pragma once

#include <QString>
#include <QList>

namespace app
{

class CLArguments
{
private:
    bool consolep;
    QList<QString> files;

    void rememberIfFile( char* name);

public:
    CLArguments( int argc, char** argv);

    bool isConsole() const { return consolep; }
    const QList<QString>& getFiles() const { return files; }
};

}; //namespace app
