
#include "Configuration.hpp"

namespace QtCha2P
{
	// static initialization
	Configuration* Configuration::m_instance = 0;

	// ctor
	Configuration::Configuration()
	{
	}

	// dtor
	Configuration::~Configuration()
	{
	}

	// create instance if no exist and return address of it
	Configuration* Configuration::getInstance()
	{
		// check if first call
		if(m_instance == 0)
		{
			// create instance
			m_instance = new Configuration();
		}

		return m_instance;
	}

	void Configuration::readConfigFile(QString filename)
	{
	}

	const QString Configuration::getNickName()
	{
		return m_nickName;
	}

	const QHostAddress Configuration::getIpAddress()
	{
		return m_ipAddress;
	}
} // namespace QtCha2P

