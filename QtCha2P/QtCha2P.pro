#-------------------------------------------------
#
# Project created by QtCreator 2009-03-16T19:56:58
#
#-------------------------------------------------

QT       += network

CONFIG   += debug_and_release

CONFIG(debug, debug|release) {
	TARGET = QtCha2P.debug
} else {
	TARGET = QtCha2P.release
}

DESTDIR  = "../bin"

TEMPLATE = app

SOURCES  += src\main.cpp\
            src\MainWindow.cpp\
            src\Configuration.cpp

HEADERS  += src\MainWindow.hpp\
			src\Configuration.hpp

FORMS    += ui/MainWindow.ui
