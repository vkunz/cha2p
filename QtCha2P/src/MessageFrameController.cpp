
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
} // namespace QtCha2P

