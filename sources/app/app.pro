OBJECTS_DIR = ../../bin/objects
DESTDIR = ../../bin
TEMPLATE = app
SOURCES += main.cpp
LIBS += -L../../bin/libs
TARGET = denfer
INCLUDEPATH += ".."

LIBS += -lcore -lgui -lhost -lperf -lsyminfo

