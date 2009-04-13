#include <QtCore/QStringList>

#include "BuddyList.hpp"

namespace QtCha2P
{

	// ctor
	BuddyList::BuddyList()
	{
		// new list
		m_ptrList = new std::list<Buddy*>;
	}

	// dtor
	BuddyList::~BuddyList()
	{
		// iterator
		std::list<Buddy*>::iterator it;
		
		// delete all buddies
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// delete
			delete (*it);
		}
		
		// delete list
		delete m_ptrList;
	}

	// add buddy
	void BuddyList::addBuddy(Buddy* buddy)
	{
		// add buddy
		m_ptrList->push_back(buddy);
	}

	// remove buddy		
	bool BuddyList::removeBuddy(const QHostAddress* const ipAddress)
	{
		// found
		bool found = false;

		// iterator
		std::list<Buddy*>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// check if available
			if((*it)->getHostAddress() == *ipAddress)
			{
				// set found
				found = true;
			}
		}
		
		// found
		if(found)
		{
			// erase element
			m_ptrList->erase(it);
			
			// delete buddy
			delete (*it);
		}
		
		return found;
	}

	// check if given nickname is available
	bool BuddyList::nicknameAvailable(const QString* const nickname)
	{
		bool ret = true;
	
		// iterator
		std::list<Buddy*>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			if((*it)->getNickName() == *nickname)
			{
				// set returnvalue
				ret = false;
				
				// leave
				break;
			}
		}
		
		return ret;
	}

	// return Nickname of given ipAddress
	QString BuddyList::getNickname(const QHostAddress* const ipAddress)
	{
		// return value
		QString ret;
		
		// iterator
		std::list<Buddy*>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// check if proper host
			if((*it)->getHostAddress() == *ipAddress)
			{
				// set returnvalue
				ret = (*it)->getNickName();
				
				// leave
				break;
			}
		}
		
		return ret;
	}
	
	Buddy BuddyList::getBuddy(QString nickname)
	{
		// return object
		Buddy ret;

		// iterator
		std::list<Buddy*>::iterator it;

		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// check if proper nickname
			if((*it)->getNickName() == nickname)
			{
				// set return
				ret = *(*it);

				// leave loop
				break;
			}
		}

		return ret;
	}
	
	// return Buddy of ipAddress
	Buddy BuddyList::getBuddy(QHostAddress host)
	{
		// return object
		Buddy ret;
		
		// iterator
		std::list<Buddy*>::iterator it;
		
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// check if proper nickname
			if((*it)->getHostAddress() == host)
			{
				// set return
				ret = *(*it);

				// leave loop
				break;
			}
		}

		return ret;
	}

	// serialize ContactList
	QString BuddyList::serializeContactList()
	{
		// string
		QString ret = "";
		
		// iterator
		std::list<Buddy*>::iterator it;

		// iterate through the whole list
		for(it = m_ptrList->begin(); it != m_ptrList->end(); it++)
		{
			// buddy to string + add buddy separator
			ret += (*it)->serializeBuddy();
			ret += ";";
		}

		return ret;
	}
	
	// build ConactList from String
	void BuddyList::buildContactList(QString contacts)
	{
		// stringlist iterator
		QStringList::const_iterator it;

		// split by buddy separator
		QStringList buddies = contacts.split(';');
		
		// split ip and nick
		QStringList buddy;
		// iterate through the stringlist
		for(it = buddies.constBegin(); it != buddies.constEnd(); it++)
		{
			// split
			buddy = (*it).split(':');

			// add new Buddy
			addBuddy(new Buddy(buddy.first(), buddy.last()));
		}
	}
	
	// return list
	std::list<Buddy*>* BuddyList::getBuddyList()
	{
		// return list
		return m_ptrList;
	}
} // namespace Qtcha2P

