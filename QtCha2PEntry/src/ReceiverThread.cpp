#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

#include "ReceiverThread.hpp"

namespace QtCha2PEntry
{
	// ctor
	ReceiverThread::ReceiverThread(QTcpSocket* socket)
	{
		// set socket
		m_socket = socket;

		// get peerAdress and store
		m_peerAddress = m_socket->peerAddress();		

		// connect socket-disconnect-signal with terminateThread
		connect(m_socket, SIGNAL(disconnected()), this, SLOT(terminateThread()));

		// connect socket-readyRead-signal with readSocketData
		connect(m_socket, SIGNAL(readyRead()), this, SLOT(readSocketData()));
	}

	// dtor
	ReceiverThread::~ReceiverThread()
	{
		// delete socket
		delete m_socket;
	}

	// terminateThread slot
	void ReceiverThread::terminateThread()
	{
		// emit signal and send all data
		emit newIncMessRecv(m_peerAddress, m_incomingData);

		// terminate thread
		quit();
	}

	// read socket data
	void ReceiverThread::readSocketData()
	{
		// append new data into the bytearray
		m_incomingData += m_socket->readAll();
	}
} // namespace QtCha2PEntry
