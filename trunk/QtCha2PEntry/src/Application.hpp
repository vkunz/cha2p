#ifndef _QTCHA2PENTRY_APPLICATION_HPP_
#define _QTCHA2PENTRY_APPLICATION_HPP_

#include <QtCore/QCoreApplication>
#include <QtCore/QTimer>

#include "Cha2PProtocol.hpp"
#include "ListenerThread.hpp"

namespace QtCha2PEntry
{
	class Application : public QCoreApplication
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

	private:
		// listenerThread
		ListenerThread* m_listener;
		
		// protocol object
		Cha2PProtocol* m_protocol;
		
		// timer to ping entry and fallback
		QTimer m_timer;

	public:
		// ctor
		Application(int argc, char* argv[]);

		// dtor
		~Application();
		
		// execute
		int exec();
		
		public slots:
			// slot: new Data arrived
			void newIncMessRecv(QHostAddress peer, QByteArray data);
			
			// slot: requst entry arrived
			void sendEntry(QString message, QHostAddress sender);
			
			// slot: timeout
			void timeOut();
	}; // class Application
} // namespace QtCha2PEntry

#endif // _QTCHA2PENTRY_APPLICATION_HPP_
