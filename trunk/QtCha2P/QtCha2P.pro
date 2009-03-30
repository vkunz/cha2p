#-------------------------------------------------
#
# Project created by QtCreator 2009-03-16T19:56:58
#
#-------------------------------------------------

QT       += network

CONFIG   += debug_and_release

CONFIG(debug, debug|release) {
	DESTDIR  = "../bin/debug"
} else {
	DESTDIR  = "../bin/release"
}

TARGET = QtCha2P

TEMPLATE = app

SOURCES  += src\main.cpp

SOURCES  += src\AbstractProtocol.cpp\
			src\Buddy.cpp\
			src\BuddyList.cpp\
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
			src\SenderThread.cpp

HEADERS  += src\AbstractProtocol.hpp\
			src\Buddy.hpp\
			src\BuddyList.hpp\
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
			src\SenderThread.hpp
