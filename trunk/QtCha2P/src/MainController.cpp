#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <QtCore/QtGlobal>

#include "BuddyList.hpp"
#include "Cha2PProtocol.hpp"
#include "ConnectWindow.hpp"
#include "MainController.hpp"
#include "MessageFrameController.hpp"

namespace QtCha2P
{
	// ctor
	MainController::MainController()
	{
		// new buddylist
		m_buddylist = new BuddyList();
	
		// new loginwindow
		m_connectWindow = new ConnectWindow();
		
		// new dispatcherthread
		m_dispatcher = new DispatcherThread();

		// new protocol
		m_protocol = new Cha2PProtocol();

		// get baseport
		m_basePort = m_protocol->getBasePort();

		// new listenerthread
		m_listener = new ListenerThread(m_basePort);

		// start thread
		m_listener->start();
		
		// connect Signal: requestContactList(QString, QString) of ConnectWindow with Slot: requestContactList(QString, QString)
		connect(m_connectWindow, SIGNAL(requestContactList(QString, QString)), this, SLOT(requestContactList(QString, QString)));
		
		// connect Signal: newIncMessRecv(QHostAddress, QByteArray) of ListenerThread with Slot: newIncMessRecv(QHostAddress, QByteArray)
		connect(m_listener, SIGNAL(newIncMessRecv(QHostAddress, QByteArray)), this, SLOT(newIncMessRecv(QHostAddress, QByteArray)));

		// show the window
		m_connectWindow->show();
	}

	// dtor
	MainController::~MainController()
	{
	}

	// slot: new Data arrived
	void MainController::newIncMessRecv(QHostAddress peer, QByteArray data)
	{
		qDebug() << "Test!";
	}

	// executed when new channel text arrives
	void MainController::newInputChannelMessage(QString inputMessage)
	{
		// ByteArray where data to send are stored
		QByteArray array;

		// generate bytearray
		array = m_protocol->generateChannelMessage(inputMessage);

		// send data to the dispatcherthread
		m_dispatcher->send(m_buddylist, m_basePort, array);
	}
	
	// executed when new private text arrives
	void MainController::newInputPrivateMessage(Buddy buddy, QString inputMessage)
	{
		// ByteArray where data to send are stored
		QByteArray array;
		
		// generate bytearray
		array = m_protocol->generatePrivateMessage(inputMessage);
		
		// send data to the dispatcherthread
		m_dispatcher->send(buddy, m_basePort, array);
	}

	// signal: ConnectWindow connect button pressed
	void MainController::requestContactList(QString host, QString nick)
	{
		// close the connectwindow
		m_connectWindow->close();
		
		// set nickname
		m_nickname = nick;
		
		// send requestcontactlist flag
		QByteArray array = m_protocol->generateRequestContacts();
		
		// generat hostaddress
		QHostAddress address(host);
		
		// send data
		m_dispatcher->send(address, m_basePort, array);

		// init the mainframecontroller
		m_mesfc = new MessageFrameController();
	}

	// signal: new incoming channel message
	void MainController::newIncomingChannelMessage(QString& message, QHostAddress& sender)
	{
		// todo
	}

	// signal: new incoming private message
	void MainController::newIncomingPrivateMessage(QString& message, QHostAddress& sender)
	{
		// todo
	}
} // namespace QtCha2P