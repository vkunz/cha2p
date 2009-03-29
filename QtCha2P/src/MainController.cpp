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

		// connect Signal: connect(QString, QString) of ConnectWindow with Slot: newConnection(QString, QString)
		QObject::connect(m_connectWindow, SIGNAL(connect(QString, QString)), this, SLOT(newConnection(QString, QString)));
		
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
	void MainController::newConnection(QString host, QString nick)
	{		
		m_connectWindow->close();

		// init the mainframecontroller
		m_mesfc = new MessageFrameController();

		//QObject::connect(m_mesfc, SIGNAL(inputMessage(QString)), this, SLOT(newInputMessage(QString)));
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
