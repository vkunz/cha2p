#include <QtGui/QApplication>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpServer>

int main(int argc, char *argv[])
{
	// the app as console
	QApplication QtCha2PEntry(argc, argv, QApplication::Tty);
	
	
	QHostAddress entry1;
	QHostAddress entry2;

	QTcpServer* server = new QTcpServer();

	server->listen(QHostAdress::Any, 3001);

	return 0;
}

newConnection()
{
	qDebug() << "Test";
}
