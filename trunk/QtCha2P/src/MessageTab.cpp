
#include <QtGui/QSizePolicy>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

#include "MessageTab.hpp"

namespace QtCha2P
{
	// ctor
	MessageTab::MessageTab(QWidget* parent) : QWidget(parent)
	{
		if (objectName().isEmpty())
		{
			setObjectName(QString::fromUtf8("MessageTab"));	
		}
		
		// QPushButton: send
		m_btnSend = new QPushButton(this);
		m_btnSend->setObjectName(QString::fromUtf8("m_btnSend"));
		m_btnSend->setGeometry(QRect(490, 350, 80, 26));
		m_btnSend->setAutoDefault(true);
		m_btnSend->setDefault(true);
		m_btnSend->setText(QString::fromUtf8("Send"));
		
		// QSizePolicy: channelmessages
		QSizePolicy sipChannelMessages(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
		sipChannelMessages.setHorizontalStretch(0);
		sipChannelMessages.setVerticalStretch(0);
				
		// QTextEdit: channelmessages
		m_txeChannelMessages = new QTextEdit(this);
		m_txeChannelMessages->setObjectName(QString::fromUtf8("m_txeChannelMessages"));
		m_txeChannelMessages->setGeometry(QRect(2, 2, 596, 300));
		m_txeChannelMessages->setSizePolicy(sipChannelMessages);
		m_txeChannelMessages->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
		m_txeChannelMessages->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		m_txeChannelMessages->setReadOnly(true);
		
		sipChannelMessages.setHeightForWidth(m_txeChannelMessages->sizePolicy().hasHeightForWidth());
		
		// QSizePolicy: inputmessage
		QSizePolicy sipInputMessage(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
		sipInputMessage.setHorizontalStretch(0);
		sipInputMessage.setVerticalStretch(0);

		// QTextEdit: inputmessage		
        m_txeInputMessage = new QTextEdit(this);
        m_txeInputMessage->setObjectName(QString::fromUtf8("m_txeInputMessage"));
        m_txeInputMessage->setGeometry(QRect(2, 320, 470, 60));
        m_txeInputMessage->setSizePolicy(sipInputMessage);
        m_txeInputMessage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		sipInputMessage.setHeightForWidth(m_txeInputMessage->sizePolicy().hasHeightForWidth());

		// connect signals and slots
		QObject::connect(m_btnSend, SIGNAL(clicked()), this, SLOT(newInputMessage()));
	}
	
	// dtor
	MessageTab::~MessageTab()
	{
	}
	
	void MessageTab::addMessage(QString message)
	{
		// add message
		m_txeChannelMessages->append(message);
	}
	
	// public slots
	void MessageTab::newInputMessage()
	{
		// tmp string
		QString tmp;
		
		// get new inputmessage and store into tmp
		tmp = m_txeInputMessage->toPlainText();
		
		// clear text
		m_txeInputMessage->clear();
		
		// emit signal
		emit inputMessage(tmp);
	}
} // namespace QtCha2P

