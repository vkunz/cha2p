#include <QtGlobal>
#include <QtCore/QString>
//#include <QtCore/QDataStream>

#include "ConnectWindow.hpp"
#include "MainController.hpp"

namespace QtCha2P
{
	// ctor
	MainController::MainController()
	{
		// new loginwindow
		m_liw = new ConnectWindow();

		// init listenerthread and run
		m_listener = new ListenerThread(3000);

		// connect signals and slots
		QObject::connect(m_liw, SIGNAL(connect(QString, QString)), this, SLOT(newConnection(QString, QString)));
				
		// show the window
		m_liw->show();
	}
	
	// dtor
	MainController::~MainController()
	{
	}
	
	
	// public slots
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

	void MainController::on(QString host, QString nick)
	{
		/*
		m_liw->close();
		m_socket.connectToHost(host, 3000);
		
		if(!m_socket.waitForConnected(10000))
		{
			qDebug() << m_socket.errorString();
		}		
		
		// new channelframe
		m_cf = new ChannelFrame();
		
		QObject::connect(m_cf, SIGNAL(inputMessage(QString)), this, SLOT(newInputMessage(QString)));
		
		// show the frame
		m_cf->show();
		*/
	}
} // namespace QtCha2P
