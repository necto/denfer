! include( ../../common_libs.pri ) {
    error( Couldn't find the common_libs.pri file! )
}

unix {
    SOURCES += "linux/*.cpp"
    HEADERS += "linux/*.hpp"
}
else {
#    SOURCES += windows/*.cpp
#   HEADERS += windows/*.hpp
}

SOURCES += *.cpp
HEADERS += *.hpp
