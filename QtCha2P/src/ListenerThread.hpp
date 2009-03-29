#ifndef _QTCHA2P_LISTENERTHREAD_HPP_
#define _QTCHA2P_LISTENERTHREAD_HPP_

#include <QtCore/QThread>
#include <QtNetwork/QTcpServer>

namespace QtCha2P
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
			
		public slots:
			// new connecion slot
			void newConnection();
			
	}; // class ListenerThread
} // namespace QtCha2P

#endif // _QTCHA2P_LISTENERTHREAD_HPP_

