#ifndef _QTCHA2P_MAINCONTROLLER_H_
#define _QTCHA2P_MAINCONTROLLER_H_

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>

#include "ChannelFrame.hpp"
#include "ConnectWindow.hpp"
#include "ListenerThread.hpp"

namespace QtCha2P
{
	class MainController : public QObject
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT
		
		private:
			// pointer to LogInWindow
			ConnectWindow* m_liw;
			
			// pointer to ChannelFrame
			ChannelFrame* m_cf;
			
			// pointer to listenerthread
			ListenerThread* m_listener;		
			
		public:
			// ctor
			MainController();
			
			// dtor
			~MainController();
			
		public slots:
			// signal: ChannelFrame send button pressed
			void newInputMessage(QString inputMessage);
			
			// signal: LogInWindow connect button pressed
			void newConnection(QString host, QString nick);

	}; // class MainController
} // namespace

#endif // _QTCHA2P_MAINCONTROLLER_H_
