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
	}

	// dtor
	ReceiverThread::~ReceiverThread()
	{
	}

} // namespace QtCha2P

