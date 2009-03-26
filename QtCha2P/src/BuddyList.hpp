#ifndef _QTCHA2P_BUDDYLIST_H_
#define _QTCHA2P_BUDDYLIST_H_

#include <list>
#include <QtCore/QString>
#include <QtNetwork/QHostAddress>

#include "Buddy.hpp"

namespace QtCha2P
{
	class BuddyList
	{
	private:
		// the list
		std::list<Buddy>* m_ptrList;

	public:
		// ctor
		BuddyList();
		
		// dtor
		virtual ~BuddyList();
		
		// add buddy
		void addBuddy(const Buddy* const buddy);
		
		// remove buddy
		void removeBuddy(const QHostAddress* const ipaddress);
		
		// check if given nickname is available
		bool nicknameAvailable(const QString* const nickname);
		
		// return Nickname of given ipAddress
		QString getNickname(const QHostAddress* const ipaddress);

	}; // class BuddyList
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDYLIST_H_
