#include <QtCore/QByteArray>
#include <QtCore/QThread>
#include <QtCore/QThreadPool>

#include "Buddy.hpp"
#include "BuddyList.hpp"
#include "Configuration.hpp"
#include "DispatcherThread.hpp"
#include "Sender.hpp"

namespace QtCha2P
{
	// ctor
	DispatcherThread::DispatcherThread()
	{
		// new pool
		m_pool = new QThreadPool();
		
		// get config
		Configuration* config = Configuration::getInstance();
		
		// set maxThreadCount
		m_pool->setMaxThreadCount(config->getThreadCounter());
	}

	// dtor
	DispatcherThread::~DispatcherThread()
	{
		// delete threadpool
		delete m_pool;
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
		// add to pool
		m_pool->start(new Sender(host, port, data));
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
		
		// wait until the threadpool is done
		m_pool->waitForDone();

		// terminate thread
		quit();
	}

	// function to send to whole buddylist
	void DispatcherThread::dispatch(BuddyList* buddylist, unsigned int port, QByteArray& data)
	{
		// start thread
		start();

		// get BuddyList
		std::list<Buddy>* list = buddylist->getBuddyList();

		// iterator
		std::list<Buddy>::iterator it;

		// iterate through whole buddylist
		for(it = list->begin(); it != list->end(); it++)
		{
			// host
			QHostAddress host = (*it).getHostAddress();

			// send
			send(host, port, data);
		}

		// wait until the threadpool is done
		m_pool->waitForDone();

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

		// wait until the threadpool is done
		m_pool->waitForDone();

		// terminate thread
		quit();
	}
} // namespace QtCha2P

