#ifndef _QTCHA2PENTRY_CHANNEL_HPP_
#define _QTCHA2PENTRY_CHANNEL_HPP_

#include <QtCore/QString>
#include <QtNetwork/QHostAddress>

namespace QtCha2PEntry
{
	class Channel : public QObject
	{
	private:
		// name
		QString m_name;
		
		// entryip
		QHostAddress m_entry;
		
		// fallback
		QHostAddress m_fallback;
		
		// entry avail flag
		bool m_entryAvailable;

		// fallback avail flag
		bool m_fallBackAvailable;
	public:
		// ctor
		Channel();
		
		// ctor with Channel-name
		Channel(QString name);
		
		// dtor
		~Channel();
		
		// check if entry is available
		const bool entryAvailable();

		// check if fallback is available
		const bool fallBackAvailable();

		// return name
		const QString getName();
		
		// return entry address
		const QHostAddress getEntry();
		
		// return fallback address
		const QHostAddress getFallBack();
		
		// set entry address
		void setEntry(const QHostAddress host);
		
		// set fallback address
		void setFallBack(const QHostAddress host);
	}; // class Channel
} // namespace QtCha2PEntry

#endif // _QTCHA2PENTRY_CHANNEL_HPP_
