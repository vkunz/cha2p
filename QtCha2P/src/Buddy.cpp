
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

} // namespace QtCha2P

