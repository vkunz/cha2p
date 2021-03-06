#ifndef _QTCHA2P_DISPATCHERTHREAD_HPP_
#define _QTCHA2P_DISPATCHERTHREAD_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QThread>
#include <QtCore/QThreadPool>

#include "Buddy.hpp"
#include "BuddyList.hpp"
#include "Sender.hpp"

namespace QtCha2P
{
	class DispatcherThread : public QThread
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT
	
		private:
			// threadpool
			QThreadPool* m_pool;

			// functions
			void start();

			// send data
			void send(QHostAddress& host, unsigned int port, QByteArray& data);

		public:
			// ctor
			DispatcherThread();

			// function to send data to buddy
			void dispatch(Buddy& buddy, unsigned int port, QByteArray& data);

			// function to send to whole buddylist
			void dispatch(BuddyList* buddylist, unsigned int port, QByteArray& data);

			// function to send to one host
			void dispatch(QHostAddress& host, unsigned int port, QByteArray& data);

			// dtor
			~DispatcherThread();
	}; // class DispatcherThread
} // namespace QtCha2P

#endif // _QTCHA2P_DISPATCHERTHREAD_HPP_

