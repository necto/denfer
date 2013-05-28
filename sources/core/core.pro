! include( ../../common_libs.pri ) {
    error( Couldn't find the common_libs.pri file! )
}

SOURCES += *.cpp

LIBS += -L../../bin/libs
LIBS += -lgui -lproc -lsyminfo -lperf
