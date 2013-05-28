CONFIG += debug
QT += script

TEMPLATE = app

OBJECTS_DIR = ../../bin/objects
DESTDIR = ../../bin
TARGET = denfer
INCLUDEPATH += ".."

# Define to do proper dll symbols import
DEFINES += "X_EXPORT=Q_DECL_IMPORT"

HEADERS += *.hpp
SOURCES += *.cpp

LIBS += -L../../bin/libs
LIBS += -lgui -lcore -lproc -lsyminfo -lperf
