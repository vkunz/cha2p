#include <QtCore/QStringList>

#include <map>

#include "BuddyList.hpp"

namespace QtCha2P
{

	// ctor
	BuddyList::BuddyList()
	{
		// new map
		m_ptrMap = new std::map<QString, Buddy*>;
	}

	// dtor
	BuddyList::~BuddyList()
	{
		// iterator
		std::map<QString, Buddy*>::iterator it;
		
		// delete all buddies
		for(it = m_ptrMap->begin(); it != m_ptrMap->end(); it++)
		{
			// delete
			delete it->second;
		}
		
		// delete list
		delete m_ptrMap;
	}

	// add buddy
	void BuddyList::addBuddy(Buddy* buddy)
	{
		// add buddy
		m_ptrMap->insert(std::pair<QString, Buddy*>(buddy->getNickName(), buddy));
	}

	// remove buddy		
	bool BuddyList::removeBuddy(const QHostAddress* const ipAddress)
	{
		// found
		bool found = false;

		// iterator
		std::map<QString, Buddy*>::iterator it;
		
		for(it = m_ptrMap->begin(); it != m_ptrMap->end(); it++)
		{
			// check if available
			if(it->second->getHostAddress() == *ipAddress)
			{
				// set found
				found = true;
			}
		}
		
		// found
		if(found)
		{
			// erase element
			m_ptrMap->erase(it);
			
			// delete buddy
			delete it->second;
		}
		
		return found;
	}

	// check if given nickname is available
	bool BuddyList::nicknameAvailable(const QString* const nickname)
	{
		bool ret = true;
	
		if(m_ptrMap->find(*nickname) != m_ptrMap->end())
		{
			// set return to false
			ret = false;
		}

		return ret;
	}

	// return Nickname of given ipAddress
	QString BuddyList::getNickname(const QHostAddress* const ipAddress)
	{
		// return value
		QString ret;
		
		// iterator
		std::map<QString, Buddy*>::iterator it;
		
		for(it = m_ptrMap->begin(); it != m_ptrMap->end(); it++)
		{
			// check if proper host
			if((it->second->getHostAddress() == *ipAddress))
			{
				// set returnvalue
				ret = it->second->getNickName();
				
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
		std::map<QString, Buddy*>::iterator it;

		for(it = m_ptrMap->begin(); it != m_ptrMap->end(); it++)
		{
			// check if proper nickname
			if(it->second->getNickName() == nickname)
			{
				// set return
				ret = *(it->second);

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
		std::map<QString, Buddy*>::iterator it;
		
		for(it = m_ptrMap->begin(); it != m_ptrMap->end(); it++)
		{
			// check if proper nickname
			if(it->second->getHostAddress() == host)
			{
				// set return
				ret = *(it->second);

				// leave loop
				break;
			}
		}

		return ret;
	}

	// serialize ContactList
	QString BuddyList::serializeBuddyList()
	{
		// string
		QString ret = "";
		
		// iterator
		std::map<QString, Buddy*>::iterator it;

		// iterate through the whole list
		for(it = m_ptrMap->begin(); it != m_ptrMap->end(); it++)
		{
			// buddy to string + add buddy separator
			ret += it->second->serializeBuddy();
			ret += ";";
		}

		return ret;
	}
	
	// build ConactList from String
	void BuddyList::buildBuddyList(QString contacts)
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
	std::map<QString, Buddy*>* BuddyList::getBuddyList()
	{
		// return list
		return m_ptrMap;
	}
} // namespace Qtcha2P

