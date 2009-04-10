#ifndef _QTCHA2P_BUDDY_HPP_
#define _QTCHA2P_BUDDY_HPP_

#include <QtCore/QString>
#include <QtNetwork/QHostAddress>

namespace QtCha2P
{
	class Buddy
	{
	private:
		// store tcp/ip address
		QHostAddress m_ipAddress;
	
		// stores Nickname
		QString m_nickname;
	
	protected:

	public:
		// ctor
		Buddy();
		
		// ctor create from ip and nickname
		Buddy(QString ip, QString nickname);
		
		// ctor create from host and nickname
		Buddy(QHostAddress ipAddress, QString nickname);
	
		// dtor
		virtual ~Buddy();
		
		// return nickname
		const QString getNickName();
		
		// return HostAddress
		const QHostAddress getHostAddress();
		
		// assign-operator
		Buddy& operator=(const Buddy buddy);
		
		// compare-operator
		bool operator==(const Buddy buddy);
		
		// return Buddy as String
		QString serializeBuddy();
	}; // class Buddy
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDY_HPP_

