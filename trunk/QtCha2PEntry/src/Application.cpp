#include <QtCore/QCoreApplication>
#include <QtNetwork/QTcpSocket>

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
		qDebug() << "Application is listening on port: " << m_protocol->getBasePort() << " to new connections!";
		
		// channel 'General'
		Channel* chan = new Channel("General");
		
		// add channel to test with
		m_channel.insert(std::pair<QString, Channel*>("General", chan));
		
		// set timer interval to 30 seconds
		m_timer.setInterval(30000);
		
		// start timer
		m_timer.start();
		
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
		// tmp
		Channel* chan = m_channel[message];
		QByteArray array;

		// new socket
		QTcpSocket socket;

		// check if entry is available
		if(!chan->entryAvailable())
		{
			// no entry available, so set new entry
			chan->setEntry(host);
		}
		else if(!chan->fallBackAvailable())
		{
			// no fallback, so set new one
			chan->setFallBack(host);
		}

		// generate protocol-frame
		array = m_protocol->generateSendEntry(chan->getEntry().toString());

		// connect to host
		socket.connectToHost(host, m_protocol->getBasePort(), QIODevice::WriteOnly);

		// try to connect, timeout: 10 ms
		if(socket.waitForConnected(10000))
		{
			// write data
			socket.write(array);

			// check if sent
			if(socket.bytesToWrite() != 0)
			{
				// force write
				socket.flush();
			}

			// data written, close connection
			socket.disconnectFromHost();
		}
	}
	
	// slot: timeout
	void Application::timeOut()
	{
		qDebug() << "Timeout!";
	}
} // namespace QtCha2PEntry
