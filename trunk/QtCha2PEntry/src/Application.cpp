#include <QtCore/QCoreApplication>

#include "Application.hpp"

namespace QtCha2PEntry
{
	// ctor
	Application::Application(int argc, char* argv[]) : QCoreApplication(argc, argv)
	{
		// new protocol object
		m_protocol = new Cha2PProtocol();

		// new listenerthread
		m_listener = new ListenerThread(m_protocol->getBasePort());

		// connect Signal: newIncMessRecv(QHostAddress, QByteArray) of ListenerThread
		// with Slot: newIncMessRecv(QHostAddress, QByteArray)
		connect(m_listener, SIGNAL(newIncMessRecv(QHostAddress, QByteArray)),
		this, SLOT(newIncMessRecv(QHostAddress, QByteArray)));
	
		// connect Signal: sendEntry(QString, QHostAddress) of Cha2PProtocol
		// with Slot: sendEntry(QString, QHostAddress)
		connect(m_protocol, SIGNAL(sendEntry(QString, QHostAddress)),
		this, SLOT(sendEntry(QString, QHostAddress)));
	
		// connect Signal: timeout () of QTimer with Slot: timeout
		connect(&m_timer, SIGNAL(timeout()), this, SLOT(timeOut()));
	}

	// dtor
	Application::~Application()
	{
	}
	
	int Application::exec()
	{
		qDebug() << "Application is listening on port: " << m_protocol->getBasePort() << " for new connections!";
		
		// set timer interval to 30 seconds
		m_timer.setInterval(30000);
		
		// start timer
		m_timer.start();
		
		qDebug() << "Timer started!";

		// execute base
		return QCoreApplication::exec();
	}
	
	// slot: new Data arrived
	void Application::newIncMessRecv(QHostAddress peer, QByteArray data)
	{
		// proceed to protocol
		m_protocol->analyzeInput(peer, data);
	}
	
	// slot: new request entry arrived, send entry
	void Application::sendEntry(QString message, QHostAddress host)
	{
		
	}
	
	// slot: timeout
	void Application::timeOut()
	{
		qDebug() << "Timeout!";
	}
} // namespace QtCha2PEntry
