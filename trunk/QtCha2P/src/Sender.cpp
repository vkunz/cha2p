#include <QtCore/QIODevice>
#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

#include "Sender.hpp"

namespace QtCha2P
{
	// ctor
	Sender::Sender(const QHostAddress& host, const unsigned int port, const QByteArray& data)
	{
		// assign hostaddress
		m_address = host;

		// assign port
		m_port = port;

		// assign data
		m_data = data;
		
		// set autodelete
		setAutoDelete(true);
	}

	// dtor
	Sender::~Sender()
	{
		delete m_socket;
	}
	
	// run
	void Sender::run()
	{
		// new socket
		m_socket = new QTcpSocket();

		// connect to host
		m_socket->connectToHost(m_address, m_port, QIODevice::WriteOnly);

		// try to connect, timeout: 10 ms
		if(m_socket->waitForConnected(10000))
		{
			// write data
			m_socket->write(m_data);
			
			// check if sent
			if(m_socket->bytesToWrite() != 0)
			{
				// force write
				m_socket->flush();
			}
			
			// data written, close connection
			m_socket->disconnectFromHost();
		}
	}
} // namespace QtCha2P
