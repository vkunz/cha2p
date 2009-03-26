#include <QtCore/QThread>
#include <QtNetwork/QTcpServer>

#include "SenderThread.hpp"

namespace QtCha2P
{
	// ctor
	SenderThread::SenderThread(QTcpSocket* socket, QByteArray* data)
	{
		// assign socket
		m_socket = socket;
		
		// connect slots and signals
		//QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(readReady()));
	}

	// dtor
	SenderThread::~SenderThread()
	{
		delete m_socket;
	}

	// run function
	void SenderThread::run()
	{
		//qDebug() << "SenderThread on";
	}
	
	void SenderThread::readReady()
	{
		/*
		qDebug() << "Read()";

		// read all
		QByteArray arr = m_socket->readAll();

		qDebug() << "Inhalt: " << arr;
		*/
	}
} // namespace QtCha2P
