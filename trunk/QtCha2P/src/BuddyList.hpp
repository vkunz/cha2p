
#include <list>

#include "Buddy.hpp"

namespace QtCha2P
{
	class BuddyList
	{
	private:
		// the list
		std::list<Buddy>* m_ptrList;
		
	protected:

	public:
		// ctor
		BuddyList();
		
		// dtor
		virtual ~BuddyList();
		
		// add buddy
		void addBuddy(const Buddy const* buddy);
		
		// remove buddy
		void removeBuddy(const QHostAddress const* ipaddress);
		
		// check if given nickname is available
		bool nicknameAvailable(const QString const* nickname);
		
		// return Nickname of given ipAddress
		QString getNickname(const QHostAddress const* ipaddress);

	}; // class BuddyList
} // namespace QtCha2P
