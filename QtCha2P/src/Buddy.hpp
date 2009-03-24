#ifndef _QTCHA2P_BUDDY_H_
#define _QTCHA2P_BUDDY_H_

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
		Buddy(QString ip, QString nickname);
	
		// dtor
		virtual ~Buddy();	

	}; // class Buddy
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDY_H_
