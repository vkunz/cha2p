#-------------------------------------------------
#
# This file is part of the Cha2P Project.
# This is the project file of QtCha2PEntry
#
#-------------------------------------------------

QT += network
QT -= gui

CONFIG += debug_and_release
CONFIG += console

CONFIG(debug, debug|release) {
	DESTDIR = "../bin/debug"
} else {
	DESTDIR = "../bin/release"
}

TARGET = QtCha2PEntry

TEMPLATE = app

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
