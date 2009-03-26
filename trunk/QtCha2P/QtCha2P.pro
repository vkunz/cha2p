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

SOURCES  += src\ChannelFrame.cpp\
			src\Configuration.cpp\
            src\LogInWindow.cpp\
			src\main.cpp\
			src\MainController.cpp
            

HEADERS  += src\ChannelFrame.hpp\
			src\Configuration.hpp\
			src\LogInWindow.hpp\
			src\MainController.hpp
			
