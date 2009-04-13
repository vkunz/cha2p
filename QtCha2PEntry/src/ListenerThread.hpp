#ifndef _QTCHA2PENTRY_LISTENERTHREAD_HPP_
#define _QTCHA2PENTRY_LISTENERTHREAD_HPP_

#include <QtCore/QThread>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpServer>

namespace QtCha2PEntry
{
	class ListenerThread : public QThread
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT
		
		private:
			// pointer to the server
			QTcpServer* m_server;
	
		public:
			// ctor
			ListenerThread(short int port);
			
			// dtor
			~ListenerThread();

		signals:
			void newIncMessRecv(QHostAddress, QByteArray);		
		
		public slots:
			// new connecion slot
			void newConnection();
		
	}; // class ListenerThread
} // namespace QtCha2PEntry

#endif // _QTCHA2PENTRY_LISTENERTHREAD_HPP_
