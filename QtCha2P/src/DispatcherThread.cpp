#include <QtCore/QByteArray>
#include <QtCore/QThread>

#include "Buddy.hpp"
#include "BuddyList.hpp"
#include "DispatcherThread.hpp"
#include "SenderThread.hpp"

namespace QtCha2P
{
	// ctor
	DispatcherThread::DispatcherThread()
	{
	}
			
	// dtor
	DispatcherThread::~DispatcherThread()
	{
	}
	
	// send function to one buddy (privatemessage)
	void DispatcherThread::send(Buddy& buddy, unsigned int port, QByteArray& data)
	{
		// new senderthread
		//m_sender = new SenderThread();
	}

	// send function to whole buddylist
	void DispatcherThread::send(BuddyList* buddylist, unsigned int port, QByteArray& data)
	{
	}
	
	// send function to send to one host
	void DispatcherThread::send(QHostAddress& host, unsigned int port, QByteArray& data)
	{
		// new senderthread
		m_sender = new SenderThread(host, port, data);
		
		// start thread
		m_sender->start();
	}
} // namespace QtCha2P

