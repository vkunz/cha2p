#ifndef _QTCHA2P_BUDDY_HPP_
#define _QTCHA2P_BUDDY_HPP_

#include <QHostAddress>
#include <QString>

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
	
		// dtor
		virtual ~Buddy();
		
		// return nickname
		QString getNickName();
		
		// assign-operator
		Buddy& operator=(Buddy buddy);
		
		bool operator==(Buddy buddy);

	}; // class Buddy
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDY_HPP_

