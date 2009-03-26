#ifndef _QTCHA2P_SENDERTHREAD_H_
#define _QTCHA2P_SENDERTHREAD_H_

#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

namespace QtCha2P
{
	class SenderThread : public QThread
	{
	Q_OBJECT
	private:
		QTcpSocket* m_socket;
	public:
		// ctor
		SenderThread(QTcpSocket* socket, QByteArray* data);
		
		// dtor
		~SenderThread();
		
		// run function
		void run();
		
	public slots:
		void readReady();
	}; // class SenderThread
} // namespace QtCha2P

#endif // _QTCHA2P_SENDERTHREAD_H_
