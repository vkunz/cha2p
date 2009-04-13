#include <QtCore/QByteArray>
#include <QtCore/QString>

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

		// new protocol
		m_protocol = new Cha2PProtocol();

		// new listenerthread
		m_listener = new ListenerThread(m_protocol->getBasePort());

		// start thread
		m_listener->start();

		// connect Signal: requestContactList(QString, QString) of ConnectWindow
		// with Slot: requestEntry(QString, QString)
		connect(m_connectWindow, SIGNAL(requestContactList(QString, QString)),
		this, SLOT(requestEntry(QString, QString)));

		// connect Signal: newIncMessRecv(QHostAddress, QByteArray) of ListenerThread
		// with Slot: newIncMessRecv(QHostAddress, QByteArray)
		connect(m_listener, SIGNAL(newIncMessRecv(QHostAddress, QByteArray)),
		this, SLOT(newIncMessRecv(QHostAddress, QByteArray)));

		// connect Signal: receivedChannelMessage(QHostAddress, QString) of Cha2PProtocol
		// with Slot: newIncomingChannelMessage(QHostAddress&, QString&)
		connect(m_protocol, SIGNAL(receivedChannelMessage(QHostAddress, QString)),
		this, SLOT(newIncomingChannelMessage(QHostAddress, QString)));

		// connect Signal: receivedPrivateMessage(QHostAddress, QString) of Cha2PProtocol
		// with Slot: newIncomingPrivateMessage(QHostAddress&, QString&)
		connect(m_protocol, SIGNAL(receivedPrivateMessage(QHostAddress, QString)),
		this, SLOT(newIncomingPrivateMessage(QHostAddress, QString)));

		// connect Signal: receivedContactList(QString) of Cha2PProtocol
		// with Slot: receivedContactList(QString)
		connect(m_protocol, SIGNAL(receivedContactList(QString)),
		this, SLOT(receivedContactList(QString)));

		// connect Signal: sendContactsList(QString, QHostAddress) of Cha2PProtocol
		// with Slot: sendContactList(QString, QHostAddress)
		connect(m_protocol, SIGNAL(sendContactsList(QString, QHostAddress)),
		this, SLOT(sendContactList(QString, QHostAddress)));

		// connect Signal: receivedEntry(QString) of Cha2PProtocol
		// with Slot: requstContactList(QString)
		connect(m_protocol, SIGNAL(receivedEntry(QString)),
		this, SLOT(requestContactList(QString)));
	
		// connect Signal: receivedHello(QHostAddress, QString) of Cha2PProtocol
		// with Slot: receivedHello(QHostAddress, QString)
		connect(m_protocol, SIGNAL(receivedHello(QHostAddress, QString)),
		this, SLOT(receivedHello(QHostAddress, QString)));

		// connect Signal: receivedGoodBye(QHostAddress) of Cha2PProtocol
		// with Slot: receivedGoodBye(QHostAddress)
		connect(m_protocol, SIGNAL(receivedGoodBye(QHostAddress)),
		this, SLOT(receivedGoodBye(QHostAddress)));
	
		// show the window
		m_connectWindow->show();
	}

	// dtor
	MainController::~MainController()
	{
		// delete listenerthread
		delete m_listener;
		
		// delete protocol
		delete m_protocol;
		
		// delete connect window
		delete m_connectWindow;
		
		// delete buddylist
		delete m_buddyList;
		
		// delete messageframecontroller
		delete m_mesfc;
		
		// delete buddylistframecontroller
		delete m_buddyListFrameController;
	}

	// slot: new Data arrived
	void MainController::newIncMessRecv(QHostAddress peer, QByteArray data)
	{
		// proceed to protocol
		m_protocol->analyzeInput(peer, data);
	}

	// executed when new channel text arrives
	void MainController::newInputChannelMessage(QString inputMessage)
	{
		// ByteArray where data to send are stored
		QByteArray array;

		// generate bytearray
		array = m_protocol->generateChannelMessage(inputMessage);

		// new dispatcher
		DispatcherThread* dispatcher = new DispatcherThread();

		// send data to the dispatcherthread
		dispatcher->dispatch(m_buddyList, m_protocol->getBasePort(), array);
	}

	// executed when new private text arrives
	void MainController::newInputPrivateMessage(Buddy buddy, QString inputMessage)
	{
		// ByteArray where data to send are stored
		QByteArray array;

		// generate bytearray
		array = m_protocol->generatePrivateMessage(inputMessage);

		// new dispatcher
		DispatcherThread* dispatcher = new DispatcherThread();

		// send data to the dispatcherthread
		dispatcher->dispatch(buddy, m_protocol->getBasePort(), array);
	}

	// slot: requestEntry
	void MainController::requestEntry(QString host, QString channel)
	{
		// send requestentry flag
		QByteArray array = m_protocol->generateRequestEntry(channel);
		
		// convert string to QHostAddress
		QHostAddress address(host);

		// new dispatcher
		DispatcherThread* dispatcher = new DispatcherThread();

		// send data
		dispatcher->dispatch(address, m_protocol->getEntryPort(), array);
	}
	
	// slot: ConnectWindow connect button pressed
	void MainController::requestContactList(QString host)
	{
		// close the connectwindow
		m_connectWindow->close();

		// send requestcontactlist flag
		QByteArray array = m_protocol->generateRequestContacts(host);

		// convert string  to QHostAddress
		QHostAddress address(host);

		// new dispatcher
		DispatcherThread* dispatcher = new DispatcherThread();

		// send data
		dispatcher->dispatch(address, m_protocol->getBasePort(), array);

		// init the mainframecontroller
		m_mesfc = new MessageFrameController();

		// init the buddylistframecontroller
		m_buddyListFrameController = new BuddyListFrameController();

		// connect signal newAddPrivateTab with slot: newPrivatetab
		connect(m_buddyListFrameController, SIGNAL(addNewPrivateTab(QString)),
		this, SLOT(newPrivateTab(QString)));
		
		// connect Signal: newChannelMessage(QString) of MessageFrameController with
		// Slot: newInputChannelMessage(QString)
		connect(m_mesfc, SIGNAL(newChannelMessage(QString)),
		this, SLOT(newInputChannelMessage(QString)));
		
		// connect Signal: newPrivateMessage(Buddy, QString) of MessageFrameController with
		// Slot: newInputPrivateMessage(Buddy, QString)
		connect(m_mesfc, SIGNAL(newPrivateMessage(Buddy, QString)),
		this, SLOT(newInputPrivateMessage(Buddy, QString)));
	}
	
	// slot: receivedContactList
	void MainController::receivedContactList(QString contacts)
	{
		// import contacts
		m_buddyList->buildContactList(contacts);
		
		// config
		Configuration* config = Configuration::getInstance();
		
		// ByteArray
		QByteArray array;

		// generate protocolframe
		array = m_protocol->generateHello(config->getNickName());

		// new dispatcher
		DispatcherThread* dispatcher = new DispatcherThread();

		// send data
		dispatcher->dispatch(m_buddyList, m_protocol->getBasePort(), array);
	}

	// slot: receivedHello
	void MainController::receivedHello(QHostAddress peer, QString nick)
	{
		// add new buddy to buddylist
		m_buddyList->addBuddy(new Buddy(peer, nick));

		// add buddy to buddylistframe
		m_buddyListFrameController->addBuddy(nick);
	}

	// slot: receivedGoodBye
	void MainController::receivedGoodBye(QHostAddress peer)
	{
		// remove buddy from buddylistframe
		m_buddyListFrameController->removeBuddy(m_buddyList->getNickname(&peer));

		// remove buddy
		m_buddyList->removeBuddy(&peer);
	}

	// slot: sendContactsList
	void MainController::sendContactList(QString ownAddress, QHostAddress peer)
	{
		// QString to store contacts list, including myself
		QString contacts = "";
		
		// get config
		Configuration* config = Configuration::getInstance();

		// add ownAddress
		config->setIpAddress(QHostAddress(ownAddress));
		
		// get serialized contactlist
		contacts += m_buddyList->serializeContactList();
		
		// add myself to contactlist
		contacts += Buddy(config->getIpAddress(), config->getNickName()).serializeBuddy();
		
		// ByteArray
		QByteArray array;

		// generate protocolframe
		array = m_protocol->generateSendContacts(contacts);

		// new dispatcher
		DispatcherThread* dispatcher = new DispatcherThread();

		// send data
		dispatcher->dispatch(peer, m_protocol->getBasePort(), array);
	}

	// slot: new incoming channel message
	void MainController::newIncomingChannelMessage(QHostAddress sender, QString message)
	{
		// add ChannelMessage
		m_mesfc->addChannelMessage(m_buddyList->getBuddy(sender), message);
	}

	// slot: new incoming private message
	void MainController::newIncomingPrivateMessage(QHostAddress sender, QString message)
	{
		// add PrivateMessage
		m_mesfc->addChannelMessage(m_buddyList->getBuddy(sender), message);
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
