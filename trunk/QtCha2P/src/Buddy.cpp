
#include "Buddy.hpp"

namespace QtCha2P
{
	// ctor
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

} // namespace QtCha2P

