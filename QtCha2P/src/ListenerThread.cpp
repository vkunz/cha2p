#include <QtGlobal>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QHostAddress>

#include "ListenerThread.hpp"

namespace QtCha2P
{
	// ctor
	ListenerThread::ListenerThread(short int port)
	{
		// create socket
		m_server = new QTcpServer();

		// connect signals and slots
		QObject::connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));

		// start listening on given port, accespt every host
		m_server->listen(QHostAddress::Any, port);
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
	}

} // namespace QtCha2P
