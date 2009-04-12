#ifndef _QTCHA2P_SENDER_HPP_
#define _QTCHA2P_SENDER_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QRunnable>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

namespace QtCha2P
{
	class Sender : public QObject, public QRunnable
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

	private:
		// peer address
		QHostAddress m_address;

		// data to send
		QByteArray m_data;

		// port to connect to
		unsigned int m_port;

		// tcp socket
		QTcpSocket* m_socket;
	public:
		// ctor
		Sender(const QHostAddress& host, const unsigned int port, const QByteArray& data);

		// dtor
		~Sender();

		// start thread
		void run();

	signals:
		void hostNotReachable();
	}; // class Sender
} // namespace QtCha2P

#endif // _QTCHA2P_SENDER_HPP_
