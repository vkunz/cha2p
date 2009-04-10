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

	// start thread
	void DispatcherThread::start()
	{
		// start dispatcher
		QThread::start();
	}
	
	// send data
	void DispatcherThread::send(QHostAddress& host, unsigned int port, QByteArray& data)
	{
		// new senderthread
		m_sender = new SenderThread(host, port, data);
		
		// start sender
		m_sender->start();
	}

	// function to send data to buddy
	void DispatcherThread::dispatch(Buddy& buddy, unsigned int port, QByteArray& data)
	{
		// start thread
		start();

		// host
		QHostAddress host = buddy.getHostAddress();

		// send
		send(host, port, data);
		
		// terminate thread
		quit();
	}

	// function to send to whole buddylist
	void DispatcherThread::dispatch(BuddyList* buddylist, unsigned int port, QByteArray& data)
	{
		// start thread
		start();

		// TODO

		// terminate thread
		quit();
	}

	// function to send to one host
	void DispatcherThread::dispatch(QHostAddress& host, unsigned int port, QByteArray& data)
	{
		// start thread
		start();

		// send
		send(host, port, data);
		
		// terminate thread
		quit();
	}
} // namespace QtCha2P

