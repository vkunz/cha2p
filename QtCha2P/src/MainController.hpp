#ifndef _QTCHA2P_MAINCONTROLLER_HPP_
#define _QTCHA2P_MAINCONTROLLER_HPP_

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>

#include "BuddyList.hpp"
#include "BuddyListFrameController.hpp"
#include "Cha2PProtocol.hpp"
#include "ConnectWindow.hpp"
#include "DispatcherThread.hpp"
#include "MessageFrameController.hpp"
#include "ListenerThread.hpp"

namespace QtCha2P
{
	class MainController : public QObject
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

		private:
			// baseport
			unsigned int m_basePort;			

			// buddylist
			BuddyList* m_buddyList;
			
			// buddylistframe controller
			BuddyListFrameController* m_buddyListFrameController;

			// LogInWindow
			ConnectWindow* m_connectWindow;

			// dispatcherthread
			DispatcherThread* m_dispatcher;

			// listenerthread
			ListenerThread* m_listener;

			// messageframe controller
			MessageFrameController* m_mesfc;

			// cha2p-protocol
			Cha2PProtocol* m_protocol;
			
			// string to store own nickname
			QString m_nickname;
			
			// QHostAddress to store own address
			QHostAddress m_address;

		public:
			// ctor
			MainController();

			// dtor
			~MainController();

		public slots:
			// slot: new Data arrived
			void newIncMessRecv(QHostAddress peer, QByteArray data);

			// slot: input text from channel tab
			void newInputChannelMessage(QString inputMessage);
			
			// slot: input text from an other tab
			void newInputPrivateMessage(Buddy buddy, QString inputMessage);

			// slot: ConnectWindow connect button pressed
			void requestContactList(QString host, QString nick);

			// slot: new incoming channel message
			void newIncomingChannelMessage(QString& message, QHostAddress& sender);

			// slot: new incoming private message
			void newIncomingPrivateMessage(QString& message, QHostAddress& sender);
			
			// slot: new private tab
			void newPrivateTab(QString nickname);

	}; // class MainController
} // namespace

#endif // _QTCHA2P_MAINCONTROLLER_HPP_

