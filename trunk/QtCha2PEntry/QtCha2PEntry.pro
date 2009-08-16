#-------------------------------------------------
#
# This file is part of the Cha2P Project.
# This is the project file of QtCha2PEntry
#
#-------------------------------------------------

CONFIG += debug_and_release
CONFIG += console

CONFIG(debug, debug|release) {
	DESTDIR = "../bin/debug"
	DEFINES += _DEBUG_
	MOC_DIR = "obj/debug"
	OBJECTS_DIR = "obj/debug"	
} else {
	DESTDIR = "../bin/release"
	MOC_DIR = "obj/release"
	OBJECTS_DIR = "obj/release"
}

QT += network
QT -= gui

TARGET = QtCha2PEntry

TEMPLATE = app

VERSION = 0.1.0

SOURCES  += src\main.cpp

SOURCES  += src\Application.cpp\
			src\Cha2PProtocol.cpp\
			src\Channel.cpp\
			src\ListenerThread.cpp\
			src\ReceiverThread.cpp

HEADERS	 += src\Application.hpp\
			src\Cha2PProtocol.hpp\
			src\Channel.hpp\
			src\ListenerThread.hpp\
			src\ReceiverThread.hpp
