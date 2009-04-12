#-------------------------------------------------
#
# This file is part of the Cha2P Project.
# This is the project file of QtCha2PEntry
#
#-------------------------------------------------

QT       += network

CONFIG   += debug_and_release
CONFIG   += console

CONFIG(debug, debug|release) {
	DESTDIR  = "../bin/debug"
} else {
	DESTDIR  = "../bin/release"
}

TARGET = QtCha2PEntry

TEMPLATE = app

SOURCES  += src/main.cpp


