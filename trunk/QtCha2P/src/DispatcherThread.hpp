#ifndef _QTCHA2P_DISPATCHERTHREAD_HPP_
#define _QTCHA2P_DISPATCHERTHREAD_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QThread>

#include "Buddy.hpp"
#include "BuddyList.hpp"
#include "SenderThread.hpp"

namespace QtCha2P
{
	class DispatcherThread : public QThread
	{
		private:
			// senderthread
			SenderThread* m_sender;
			
			// functions
			void start();

		public:
			// ctor
			DispatcherThread();

			// constructor to send data to a buddy
			void dispatch(Buddy& buddy, unsigned int port, QByteArray& data);

			// constructor to send to whole buddylist
			void dispatch(BuddyList* buddylist, unsigned int port, QByteArray& data);
			
			// constructor to send to one host
			void dispatch(QHostAddress& host, unsigned int port, QByteArray& data);

			// dtor
			~DispatcherThread();
	}; // class DispatcherThread
} // namespace QtCha2P

#endif // _QTCHA2P_DISPATCHERTHREAD_HPP_

