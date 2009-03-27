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

SOURCES  += src\main.cpp\

SOURCES  += src\ChannelFrame.cpp\
            src\ConnectWindow.cpp\
			src\Configuration.cpp\
			src\DispatcherThread.cpp\
			src\ListenerThread.cpp\
			src\MainController.cpp\
			src\ReceiverThread.cpp\
			src\SenderThread.cpp

HEADERS  += src\ChannelFrame.hpp\
			src\ConnectWindow.hpp\
			src\Configuration.hpp\
			src\DispatcherThread.hpp\
			src\ListenerThread.hpp\
			src\MainController.hpp\
			src\ReceiverThread.hpp\
			src\SenderThread.hpp
