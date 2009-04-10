#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <QtCore/QtGlobal>

#include "BuddyList.hpp"
#include "Cha2PProtocol.hpp"
#include "Configuration.hpp"
#include "ConnectWindow.hpp"
#include "MainController.hpp"
#include "MessageFrameController.hpp"

namespace QtCha2P
{
	// ctor
	MainController::MainController()
	{
		// new buddylist
		m_buddyList = new BuddyList();

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
		unsigned char proto;
		unsigned int length;
		QString message;

		// data stream to extract protbit and length
		QDataStream stream(&data, QIODevice::ReadWrite);

		// get message and store into bytearray
		QByteArray tmp = data.right(data.length() - (sizeof(unsigned char) + sizeof(unsigned int)));

		// extract protbit
		stream >> proto;

		// extract length
		stream >> length;

		// get message
		message = tmp;
	}

	// executed when new channel text arrives
	void MainController::newInputChannelMessage(QString inputMessage)
	{
		// ByteArray where data to send are stored
		QByteArray array;

		// generate bytearray
		array = m_protocol->generateChannelMessage(inputMessage);

		// send data to the dispatcherthread
		m_dispatcher->send(m_buddyList, m_basePort, array);
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

		// get config object
		QtCha2P::Configuration* config = QtCha2P::Configuration::getInstance();

		// set own nickname
		config->setNickName(nick);

		// send requestcontactlist flag
		QByteArray array = m_protocol->generateRequestContacts(host);

		// convert string to QHostAddress
		QHostAddress address(host);

		// send data
		m_dispatcher->send(address, m_basePort, array);

		// init the mainframecontroller
		m_mesfc = new MessageFrameController();

		// init the buddylistframecontroller
		m_buddyListFrameController = new BuddyListFrameController();

		// connect signal newAddPrivateTab with slot: newPrivatetab
		connect(m_buddyListFrameController, SIGNAL(addNewPrivateTab(QString)), this, SLOT(newPrivateTab(QString)));
		
		// add myself to BuddyList
		m_buddyListFrameController->addBuddy(config->getNickName());
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
	
	// slot: new private tab
	void MainController::newPrivateTab(QString nickname)
	{
		// get Buddy
		Buddy buddy = m_buddyList->getBuddy(nickname);	

		// add new tab
		m_mesfc->addPrivateChatTab(buddy);
	}
} // namespace QtCha2P