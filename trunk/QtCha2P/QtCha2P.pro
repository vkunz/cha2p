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
            src\LogInWindow.cpp\
            src\Configuration.cpp

HEADERS  += src\LogInWindow.hpp\
			src\Configuration.hpp

FORMS    += ui/LogInWindow.ui
