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

	// function to send data to buddy
	void DispatcherThread::dispatch(Buddy& buddy, unsigned int port, QByteArray& data)
	{
		// host
		QHostAddress host = buddy.getHostAddress();

		// dispatch
		dispatch(host, port, data);
	}

	// function to send to whole buddylist
	void DispatcherThread::dispatch(BuddyList* buddylist, unsigned int port, QByteArray& data)
	{
		// TODO
	}

	// function to send to one host
	void DispatcherThread::dispatch(QHostAddress& host, unsigned int port, QByteArray& data)
	{
		// start thread
		start();

		// new senderthread
		m_sender = new SenderThread(host, port, data);
	}
} // namespace QtCha2P

