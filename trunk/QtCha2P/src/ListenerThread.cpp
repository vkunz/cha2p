#include <QtGlobal>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QHostAddress>

#include "ListenerThread.hpp"
#include "ReceiverThread.hpp"

namespace QtCha2P
{
	// ctor
	ListenerThread::ListenerThread(short int port)
	{
		// create socket
		m_server = new QTcpServer();

		// connect signals and slots
		connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));

		// start listening on given port, accespt every host
		m_server->listen(QHostAddress::Any, port);
		
		qDebug() << "ListenerThread started";
	}

	// dtor
	ListenerThread::~ListenerThread()
	{
		// remove
		delete m_server;
	}

	// new connection slot
	void ListenerThread::newConnection()
	{
		// create a new receiverthread and assign the new connection
		ReceiverThread* receiver = new ReceiverThread(m_server->nextPendingConnection());

		// start the new thread
		receiver->start();
		
		// connect ReceiverThread Signal: newDataReceived with Signal newDataReceived
		connect(receiver, SIGNAL(newIncMessRecv(QHostAddress, QByteArray)), this, SIGNAL(newIncMessRecv(QHostAddress, QByteArray)));
		
		qDebug() << "New Connection arrived";
	}
} // namespace QtCha2P
