#ifndef _QTCHA2P_DISPATCHERTHREAD_HPP_
#define _QTCHA2P_DISPATCHERTHREAD_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QThread>

#include "Buddy.hpp"
#include "BuddyList.hpp"

namespace QtCha2P
{
	class DispatcherThread : public QThread
	{
		private:
		
		public:
			// ctor: message to one buddy
			DispatcherThread(Buddy* buddy, QByteArray data);
			
			// ctor: message to whole buddylist
			DispatcherThread(BuddyList* buddylist, QByteArray data);
			
			// dtor
			~DispatcherThread();
			
	}; // class DispatcherThread
} // namespace QtCha2P

#endif // _QTCHA2P_DISPATCHERTHREAD_HPP_

