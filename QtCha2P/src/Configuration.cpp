#include "Configuration.hpp"

namespace QtCha2P
{
	// static initialization
	Configuration* Configuration::m_instance = NULL;

	// ctor
	Configuration::Configuration()
	{
		// set threadcounter to 10 by default
		m_threads = 10;
	}

	// dtor
	Configuration::~Configuration()
	{
	}

	// create instance if no exist and return address of it
	Configuration* Configuration::getInstance()
	{
		// check if first call
		if(m_instance == NULL)
		{
			// create instance
			m_instance = new Configuration();
		}

		return m_instance;
	}

	void Configuration::readConfigFile(QString filename)
	{
	}

	// return own ipaddress
	const QHostAddress Configuration::getIpAddress()
	{
		// return ip
		return m_ipAddress;
	}

	// return own nick
	const QString Configuration::getNickName()
	{
		// return nick
		return m_nickName;
	}
	
	// return maxthreadcounter
	unsigned int Configuration::getThreadCounter()
	{
		// return counter
		return m_threads;
	}

	// set own ipAddress
	void Configuration::setIpAddress(const QHostAddress ipAddress)
	{
		// set ipaddress
		m_ipAddress = ipAddress;	
	}
	
	// set own nickName
	void Configuration::setNickName(const QString nick)
	{
		// set nickname
		m_nickName = nick;
	}

	// set maxthreadcounter
	void Configuration::setThreadCounter(const unsigned int counter)
	{
		// set counter
		m_threads = counter;
	}
} // namespace QtCha2P

