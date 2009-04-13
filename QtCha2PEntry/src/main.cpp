#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpServer>

#include "Application.hpp"

int main(int argc, char *argv[])
{
	qDebug() << "QtCha2PEntry started!";
	
	// the app as console
	QtCha2PEntry::Application App(argc, argv);
	
	// execute
	return App.exec();
}
