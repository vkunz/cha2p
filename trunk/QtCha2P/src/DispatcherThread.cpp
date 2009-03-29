#include <QtCore/QByteArray>
#include <QtCore/QThread>

#include "Buddy.hpp"
#include "BuddyList.hpp"
#include "DispatcherThread.hpp"

namespace QtCha2P
{
	// ctor: message to one buddy
	DispatcherThread::DispatcherThread(Buddy* buddy, QByteArray data)
	{
		// todo
	}
	
	// ctor: message to whole buddylist
	DispatcherThread::DispatcherThread(BuddyList* buddylist, QByteArray data)
	{
		// todo
	}
			
	// dtor
	DispatcherThread::~DispatcherThread()
	{
	}
} // namespace QtCha2P

