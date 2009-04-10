#include "Buddy.hpp"

namespace QtCha2P
{
	// ctor
	Buddy::Buddy()
	{
	}
	
	// ctor create from ip and nickname
	Buddy::Buddy(QString ip, QString nickname)
	{
		// set ipaddress
		m_ipAddress.setAddress(ip);
		
		// set nickname
		m_nickname = nickname;
	}
	
	// dtor
	Buddy::~Buddy()
	{
	}
	
	QString Buddy::getNickName()
	{
		return m_nickname;
	}
	
	// assign-operator
	Buddy& Buddy::operator=(Buddy buddy)
	{
		// ip address
		m_ipAddress = buddy.m_ipAddress;

		// nick
		m_nickname = buddy.m_nickname;

		return *this;
	}
	
	bool Buddy::operator==(Buddy buddy)
	{
		bool ret = false;

		if((m_ipAddress == buddy.m_ipAddress) && (m_nickname == buddy.m_nickname))
		{
			ret = true;
		}
		
		return ret;
	}
} // namespace QtCha2P

