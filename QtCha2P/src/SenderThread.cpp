#include <QtCore/QIODevice>
#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QtGlobal>

#include "SenderThread.hpp"

namespace QtCha2P
{
	// ctor
	SenderThread::SenderThread(QHostAddress& host, unsigned int port, QByteArray& data)
	{
		// new socket
		m_socket = new QTcpSocket();

		// assign hostaddress
		m_address = host;

		// assign port
		m_port = port;

		// assign data
		m_data = data;
	}

	// dtor
	SenderThread::~SenderThread()
	{
		delete m_socket;
	}
	
	// start thread
	void SenderThread::start()
	{
		// start thread
		QThread::start();

		// connect to host
		m_socket->connectToHost(m_address, m_port, QIODevice::WriteOnly);

		// try to connect, timeout: 10 ms
		if(m_socket->waitForConnected(10000))
		{
			// write data
			m_socket->write(m_data);

			// data written, close connection
			m_socket->close();
		}
	}
} // namespace QtCha2P
