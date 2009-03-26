#ifndef _QTCHA2P_CHANNELFRAME_H_
#define _QTCHA2P_CHANNELFRAME_H_

#include <QtGui/QFrame>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

namespace QtCha2P
{
	class ChannelFrame : public QFrame
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

	private:
		// attributes
		QPushButton* 	m_btnSend;
		QTextEdit*		m_txeChannelMessages;
	    QTextEdit*		m_txeInputMessage;

	public:
		// ctor
		ChannelFrame(QWidget* parent = 0);
		
		// dtor
		~ChannelFrame();
		
	signals:
		void inputMessage(QString inputMessage);
		
	public slots:
		void newInputMessage();
	}; // class ChannelFrame
} // namespace QtCha2P

#endif // _QTCHA2P_CHANNELFRAME_H_
