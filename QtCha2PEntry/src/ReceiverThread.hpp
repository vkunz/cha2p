#ifndef _QTCHA2PENTRY_RECEIVERTHREAD_HPP_
#define _QTCHA2PENTRY_RECEIVERTHREAD_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QThread>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

namespace QtCha2PEntry
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
} // namespace QtCha2PEntry

#endif // _QTCHA2PENTRY_RECEIVERTHREAD_HPP_

