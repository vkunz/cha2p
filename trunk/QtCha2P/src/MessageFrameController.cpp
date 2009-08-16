#include <QtCore/QTime>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>

#include "MessageFrame.hpp"
#include "MessageFrameController.hpp"
#include "MessageTab.hpp"

namespace QtCha2P
{
	// ctor
	MessageFrameController::MessageFrameController()
	{
		// init the frame
		m_frame = new MessageFrame();

		// init the tab widget
		m_widget = new QTabWidget(m_frame);
		
		// vertical box layout
		QVBoxLayout *mainLayout = new QVBoxLayout;
		
		// add widgets to layout
		mainLayout->addWidget(m_widget);
		
		// set layout
		m_frame->setLayout(mainLayout);
		
		// new tab
		m_tab = new MessageTab();
		
		// connect
		connect(m_tab, SIGNAL(inputMessage(QString)), this, SLOT(newInputMessage(QString)));
		
		// add new widget, channel frame
		m_widget->addTab(m_tab, "Channel");

		// show the frame
		m_frame->show();
	}

	// dtor
	MessageFrameController::~MessageFrameController()
	{
	}
	
	void MessageFrameController::addPrivateChatTab(Buddy buddy)
	{
		// new tab
		m_tab = new MessageTab();
		
		// connect tab inputtext with general inputslot
		connect(m_tab, SIGNAL(inputMessage(QString)), this, SLOT(newInputMessage(QString)));
		
		// add buddy to map and new widget
		m_tabs.insert(std::pair<unsigned int, Buddy>(m_widget->addTab(m_tab, buddy.getNickName()), buddy));
	}
	
	void MessageFrameController::newInputMessage(QString inputMessage)
	{
		// if index of currenttab equals zero it is the channel
		if(m_widget->currentIndex() == 0)
		{
			// emit new channelmessage
			emit newChannelMessage(inputMessage);
		}
		else
		{
			// emit new privatemessage, buddy from map
			emit newPrivateMessage(m_tabs[m_widget->currentIndex()], inputMessage);
		}
	}
	
	// add new channelmessage
	void MessageFrameController::addChannelMessage(Buddy sender, QString message)
	{
		// tmp string
		QString tmp;

		// time
		QTime time;

		// MessageTab pointer
		MessageTab* tab = static_cast<MessageTab*>(m_widget->widget(0));

		// prepare message	(timestamp) blanc Nickname: newline message
		time = QTime::currentTime();

		tmp = "(" + time.toString("hh:mm:ss:") + ") ";
		tmp += sender.getNickName();
		tmp += "\n" + message;

		// add message
		tab->addMessage(tmp);
	}

	// add new privateMessage
	void MessageFrameController::addPrivateMessage(Buddy sender, QString message)
	{
		// tmp string
		QString tmp;
		
		qDebug() << "here: ";

		// time
		QTime time;

		// iterator
		std::map<unsigned int, Buddy>::iterator it;

		// MessageTab pointer
		MessageTab* tab = NULL;

		// iterate through the list
		for(it = m_tabs.begin(); it != m_tabs.end(); it++)
		{
			if((*it).second == sender)
			{
				// set widget
				tab = static_cast<MessageTab*>(m_widget->widget((*it).first));
				
				qDebug() << "if";
				
				// found
				break;
			}
			else
			{
				// not found, so do not exist yet, create
				addPrivateChatTab(sender);
				
				qDebug() << "else";
				
				// execute again
				addPrivateMessage(sender, message);
			}
		}

		// prepare message	(timestamp) blanc Nickname: newline message
		time = QTime::currentTime();

		tmp = "(" + time.toString("hh:mm:ss") + ") ";
		tmp += sender.getNickName();
		tmp += "\n" + message;

		// add message
		tab->addMessage(tmp);
	}
} // namespace QtCha2P

