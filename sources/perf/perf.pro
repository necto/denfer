! include( ../../common_libs.pri ) {
    error( Couldn't find the common_libs.pri file! )
}

unix {
    SOURCES += "linux/*.cpp"
    HEADERS += "linux/*.hpp"
}
else {
    SOURCES += windows/simple_counter.cpp
    HEADERS += windows/simple_counter.hpp
}

SOURCES += *.cpp
HEADERS += *.hpp
