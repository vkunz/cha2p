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
	
	Buddy::Buddy(QHostAddress ipAddress, QString nickname)
	{
		// set ipaddress
		m_ipAddress = ipAddress;
		
		// set nickname
		m_nickname = nickname;
	}
	
	// dtor
	Buddy::~Buddy()
	{
	}
	
	const QString Buddy::getNickName()
	{
		// return nick
		return m_nickname;
	}
	
	// return HostAddress
	const QHostAddress Buddy::getHostAddress()
	{
		// return host
		return m_ipAddress;
	}
	
	// assign-operator
	Buddy& Buddy::operator=(const Buddy buddy)
	{
		// ip address
		m_ipAddress = buddy.m_ipAddress;

		// nick
		m_nickname = buddy.m_nickname;

		return *this;
	}
	
	bool Buddy::operator==(const Buddy buddy)
	{
		bool ret = false;

		if((m_ipAddress == buddy.m_ipAddress) && (m_nickname == buddy.m_nickname))
		{
			ret = true;
		}
		
		return ret;
	}
	
	// return Buddy as String
	QString Buddy::serializeBuddy()
	{
		// return 'ip:nickname'
		return m_ipAddress.toString() + ":" + m_nickname;
	}

} // namespace QtCha2P

