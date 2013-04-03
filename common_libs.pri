#Includes common configuration for all subdirectory .pro files.
INCLUDEPATH += . ..
WARNINGS += -Wall

TEMPLATE = lib

# Special define to do proper export in dll libs
DEFINES += "X_EXPORT=Q_DECL_EXPORT"

# The following keeps the generated files at least somewhat separate 
# from the source files.
OBJECTS_DIR = ../../bin/objects
DESTDIR = ../../bin/libs

# Specify source and header files location
#SOURCES = *.cpp
HEADERS = *.hpp
