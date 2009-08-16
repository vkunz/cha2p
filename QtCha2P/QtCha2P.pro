#-------------------------------------------------
#
# This file is part of the Cha2P Project.
# This is the project file of QtCha2P-Client
#
#-------------------------------------------------

CONFIG += debug_and_release
CONFIG -= console

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

# add a debug console in debug mode on windows
win32:debug{
		CONFIG += console
}

QT += network

TARGET = QtCha2P

TEMPLATE = app

VERSION = 0.1.0

SOURCES  += src\main.cpp

SOURCES  += src\Buddy.cpp\
			src\BuddyList.cpp\
			src\BuddyListFrame.cpp\
			src\BuddyListFrameController.cpp\
			src\Cha2PProtocol.cpp\
			src\Configuration.cpp\
			src\ConnectWindow.cpp\
			src\DispatcherThread.cpp\
			src\ListenerThread.cpp\
			src\MainController.cpp\
			src\MessageFrame.cpp\
			src\MessageFrameController.cpp\
			src\MessageTab.cpp\
			src\ReceiverThread.cpp\
			src\Sender.cpp

HEADERS  += src\Buddy.hpp\
			src\BuddyList.hpp\
			src\BuddyListFrame.hpp\
			src\BuddyListFrameController.hpp\
			src\Cha2PProtocol.hpp\
			src\Configuration.hpp\
			src\ConnectWindow.hpp\
			src\DispatcherThread.hpp\
			src\ListenerThread.hpp\
			src\MainController.hpp\
			src\MessageFrame.hpp\
			src\MessageFrameController.hpp\
			src\MessageTab.hpp\
			src\ReceiverThread.hpp\
			src\Sender.hpp
