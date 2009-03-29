#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

#include "ReceiverThread.hpp"

namespace QtCha2P
{
	// ctor
	ReceiverThread::ReceiverThread(QTcpSocket* socket)
	{
		// set socket
		m_socket = socket;

		// get peerAdress and store
		m_peerAddress = m_socket->peerAddress();		
		
		// connect socket-disconnect-signal with terminateThread
		QObject::connect(m_socket, SIGNAL(disconnect()), this, SLOT(terminateThread()));
		
		// connect socket-readyRead-signal with readSocketData
		QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(readSocketData()));
	}

	// dtor
	ReceiverThread::~ReceiverThread()
	{
	}
	
	// terminateThread slot
	void ReceiverThread::terminateThread()
	{
		// emit signal and send all data
		emit newIncomingMessageReceived(m_peerAddress, m_incomingData);
		
		// terminate thread
		quit();
	}
	
	// read socket data
	void ReceiverThread::readSocketData()
	{
		// append new data into the bytearray
		m_incomingData += m_socket->readAll();
	}
} // namespace QtCha2P

