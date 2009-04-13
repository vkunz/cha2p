#include "Channel.hpp"

namespace QtCha2PEntry
{
	// ctor
	Channel::Channel()
	{
		// no entry available
		m_entryAvailable = false;
		m_fallBackAvailable = false;
	}
	
	// ctor with Channel-name
	Channel::Channel(QString name)
	{
		// set name
		m_name = name;

		// no entry available
		m_entryAvailable = false;
		m_fallBackAvailable = false;
	}
	
	// dtor
	Channel::~Channel()
	{
	}
	
	// check if entry is available
	const bool Channel::entryAvailable()
	{
		// return entry
		return m_entryAvailable;
	}

	// check if fallback is available
	const bool Channel::fallBackAvailable()
	{
		// return fallback
		return m_fallBackAvailable;
	}
	
	// return name
	const QString Channel::getName()
	{
		// return
		return m_name;
	}
	
	// return entry address
	const QHostAddress Channel::getEntry()
	{
		// get entry address
		return m_entry;
	}
	
	// return fallback address
	const QHostAddress Channel::getFallBack()
	{
		// get fallback address
		return m_fallback;
	}
	
	// set entry address
	void Channel::setEntry(const QHostAddress host)
	{
		// set entry address
		m_entry = host;
		
		// now available
		m_entryAvailable = true;
	}
	
	// set fallback address
	void Channel::setFallBack(const QHostAddress host)
	{
		// set fallback address
		m_fallback = host;
		
		// now available
		m_entryAvailable = true;
	}
} // namespace QtCha2PEntry
