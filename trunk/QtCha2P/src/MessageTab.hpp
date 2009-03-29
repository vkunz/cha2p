#ifndef _QTCHA2P_MESSAGETAB_HPP_
#define _QTCHA2P_MESSAGETAB_HPP_

#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

namespace QtCha2P
{
	class MessageTab : public QWidget
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
		MessageTab(QWidget* parent = 0);
		
		// dtor
		~MessageTab();
		
	signals:
		void inputMessage(QString inputMessage);
		
	public slots:
		void newInputMessage();

	}; // class MessageTab
} // namespace QtCha2P

#endif // _QTCHA2P_MESSAGETAB_HPP_

