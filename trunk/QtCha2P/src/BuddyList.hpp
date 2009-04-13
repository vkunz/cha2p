#ifndef _QTCHA2P_BUDDYLIST_HPP_
#define _QTCHA2P_BUDDYLIST_HPP_

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
		std::list<Buddy*>* m_ptrList;

	public:
		// ctor
		BuddyList();
		
		// dtor
		virtual ~BuddyList();
		
		// add buddy
		void addBuddy(Buddy* buddy);
		
		// remove buddy
		bool removeBuddy(const QHostAddress* const ipAddress);
		
		// check if given nickname is available
		bool nicknameAvailable(const QString* const nickname);
		
		// return Nickname of given ipAddress
		QString getNickname(const QHostAddress* const ipAddress);
		
		// return Buddy of given nickname
		Buddy getBuddy(QString nickname);
		
		// return Buddy of ipAddress
		Buddy getBuddy(QHostAddress host);
		
		// serialize ContactList
		QString serializeContactList();
		
		// build ConactList from String
		void buildContactList(QString contacts);
		
		// return list
		std::list<Buddy*>* getBuddyList();
	}; // class BuddyList
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDYLIST_HPP_

