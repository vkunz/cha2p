#ifndef _QTCHA2P_RECEIVERTHREAD_HPP_
#define _QTCHA2P_RECEIVERTHREAD_HPP_

#include <QtCore/QString>
#include <QtCore/QThread>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

namespace QtCha2P
{
	class ReceiverThread : public QThread
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

		private:
			// pointer to socket
			QTcpSocket* m_socket;

			// get peer address
			QHostAddress m_peerAddress;

			// store incoming message
			QByteArray m_incomingData;

		public:
			// ctor
			ReceiverThread(QTcpSocket* socket);

			// dtor
			~ReceiverThread();

		signals:
			void newIncMessRecv(QHostAddress, QByteArray);

		public slots:
			// theread termination
			void terminateThread();

			// reads data available on socket
			void readSocketData();

	}; // class ReceiverThread
} // namespace QtCha2P

#endif // _QTCHA2P_RECEIVERTHREAD_HPP_

