#include <QtGlobal>
#include <QtCore/QString>

#include "ConnectWindow.hpp"
#include "MainController.hpp"
#include "MessageFrameController.hpp"

namespace QtCha2P
{
	// ctor
	MainController::MainController()
	{
		// new loginwindow
		m_connectWindow = new ConnectWindow();

		// init listenerthread
		m_listener = new ListenerThread(3000);

		// start thread
		m_listener->start();

		// connect Signal: requestContactList(QString, QString) of ConnectWindow with Slot: requestContactList(QString, QString)
		QObject::connect(m_connectWindow, SIGNAL(requestContactList(QString, QString)), this, SLOT(requestContactList(QString, QString)));

		// show the window
		m_connectWindow->show();
	}

	// dtor
	MainController::~MainController()
	{
	}

	// signal: ChannelFrame send button pressed
	void MainController::newInputMessage(QString inputMessage)
	{
		/*
		qDebug() << inputMessage;

		QByteArray arr;

		QDataStream dstream(&arr, QIODevice::WriteOnly);

		const unsigned char proto = 0;
		const unsigned char len = inputMessage.length();

		dstream << proto << len;

		qDebug() << "len normal: " << len;

		qDebug() << "len gecastet: " << (char)len;

		m_socket.write(arr);

		m_socket.write(inputMessage.toAscii());

		qDebug() << inputMessage.toAscii();

		qDebug() << m_socket.bytesToWrite();
		qDebug() << m_socket.bytesAvailable();
		*/
	}

	// signal: ConnectWindow connect button pressed
	void MainController::requestContactList(QString host, QString nick)
	{
		// close the connectwindow
		//m_connectWindow->close();

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
