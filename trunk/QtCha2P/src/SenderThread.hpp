#ifndef _QTCHA2P_SENDERTHREAD_HPP_
#define _QTCHA2P_SENDERTHREAD_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QThread>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

namespace QtCha2P
{
	class SenderThread : public QThread
	{
	Q_OBJECT
	private:
		// socket
		QTcpSocket* m_socket;

		// peer address
		QHostAddress m_address;

		// port to connect to
		unsigned int m_port;

		// data to send
		QByteArray m_data;
	public:
		// ctor
		SenderThread(QHostAddress& host, unsigned int port, QByteArray& data);

		// dtor
		~SenderThread();

		// start thread
		void start();

	}; // class SenderThread
} // namespace QtCha2P

#endif // _QTCHA2P_SENDERTHREAD_HPP_
