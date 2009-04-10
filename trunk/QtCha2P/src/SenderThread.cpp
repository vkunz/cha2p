#include <QtCore/QIODevice>
#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

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

#if defined(_QTCHA2P_DEBUG_)
		unsigned char proto;
		unsigned int length;
		QString message;

		// data stream to extract protbit and length
		QDataStream stream(&data, QIODevice::ReadWrite);

		// get message and store into bytearray
		QByteArray tmp = data.right(data.length() - (sizeof(unsigned char) + sizeof(unsigned int)));

		// extract protbit
		stream >> proto;

		// extract length
		stream >> length;

		// get message
		message = tmp;

		qDebug() << "----------OUTGOING-----------------";
		qDebug() << "Protocol: " << proto;
		qDebug() << "Length: " << length;
		qDebug() << "Message: " << message;
		qDebug() << "Server-IP: " << host.toString();
		qDebug() << "-----------------------------------";
#endif

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
