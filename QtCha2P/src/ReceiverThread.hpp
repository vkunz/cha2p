#ifndef _QTCHA2P_RECEIVERTHREAD_HPP_
#define _QTCHA2P_RECEIVERTHREAD_HPP_

#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

namespace QtCha2P
{
	class ReceiverThread : public QThread
	{
		private:
			// pointer to socket
			QTcpSocket* m_socket;
			
		public:
			// ctor
			ReceiverThread(QTcpSocket* socket);
			
			// dtor
			~ReceiverThread();

	}; // class ReceiverThread
} // namespace QtCha2P

#endif // _QTCHA2P_RECEIVERTHREAD_HPP_

