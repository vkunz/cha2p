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
		public:
			// ctor
			DispatcherThread();

			// dtor
			~DispatcherThread();

			// send function to one buddy (privatemessage)
			void send(Buddy& buddy, unsigned int port, QByteArray& data);

			// send function to whole buddylist
			void send(BuddyList* buddylist, unsigned int port, QByteArray& data);
			
			// send function to send to one host
			void send(QHostAddress& host, unsigned int port, QByteArray& data);

	}; // class DispatcherThread
} // namespace QtCha2P

#endif // _QTCHA2P_DISPATCHERTHREAD_HPP_

