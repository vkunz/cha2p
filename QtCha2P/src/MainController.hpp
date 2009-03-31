#ifndef _QTCHA2P_MAINCONTROLLER_HPP_
#define _QTCHA2P_MAINCONTROLLER_HPP_

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>

#include "Cha2PProtocol.hpp"
#include "ConnectWindow.hpp"
#include "MessageFrameController.hpp"
#include "ListenerThread.hpp"

namespace QtCha2P
{
	class MainController : public QObject
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

		private:
			// LogInWindow
			ConnectWindow* m_connectWindow;

			// listenerthread
			ListenerThread* m_listener;

			// messageframe controller
			MessageFrameController* m_mesfc;
			
			// cha2p-protocol
			Cha2PProtocol* m_protocol;
			
		public:
			// ctor
			MainController();

			// dtor
			~MainController();

		public slots:
			// slot: new Data arrived
			void newIncMessRecv(QHostAddress peer, QByteArray data);
			
			// slot: ChannelFrame send button pressed
			void newInputMessage(QString inputMessage);

			// slot: ConnectWindow connect button pressed
			void requestContactList(QString host, QString nick);

			// slot: new incoming channel message
			void newIncomingChannelMessage(QString& message, QHostAddress& sender);

			// slot: new incoming private message
			void newIncomingPrivateMessage(QString& message, QHostAddress& sender);

	}; // class MainController
} // namespace

#endif // _QTCHA2P_MAINCONTROLLER_HPP_

