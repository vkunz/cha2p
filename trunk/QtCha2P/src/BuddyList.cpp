#include "BuddyList.hpp"

namespace QtCha2P
{

	// ctor
	BuddyList::BuddyList()
	{
		// new list
		m_ptrList = new std::list<Buddy>;
	}

	// dtor
	BuddyList::~BuddyList()
	{
		// delete list
		delete m_ptrList;
	}

	// add buddy
	void BuddyList::addBuddy(const Buddy* const buddy)
	{
		// add buddy
		m_ptrList->push_back(*buddy);
	}

	// remove buddy		
	void BuddyList::removeBuddy(const QHostAddress* const ipaddress)
	{
		// iterator
		std::list<Buddy>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// todo
		}
	}

	// check if given nickname is available
	bool BuddyList::nicknameAvailable(const QString* const nickname)
	{
		// iterator
		std::list<Buddy>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// todo
		}
		
		return true;
	}

	// return Nickname of given ipAddress
	QString BuddyList::getNickname(const QHostAddress* const ipaddress)
	{
		// return value
		QString ret;
		
		// iterator
		std::list<Buddy>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// todo
		}
		
		return ret;
	}
	
	Buddy BuddyList::getBuddy(QString nickname)
	{
		// return object
		Buddy ret;

		// iterator
		std::list<Buddy>::iterator it;

		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// check if proper nickname
			if((*it).getNickName() == nickname)
			{
				// set return
				ret = (*it);

				// leave loop
				break;
			}
		}

		return ret;
	}
} // namespace Qtcha2P

