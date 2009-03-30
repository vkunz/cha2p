
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
		
		QVBoxLayout *mainLayout = new QVBoxLayout;
		mainLayout->addWidget(m_widget);
		m_frame->setLayout(mainLayout);
		
		// add new widget, channel frame
		m_widget->addTab(new MessageTab(), "Channel");
		m_widget->addTab(new MessageTab(), "Buddy1");
		m_widget->addTab(new MessageTab(), "Buddy2");

		// show the frame
		m_frame->show();
	}

	// dtor
	MessageFrameController::~MessageFrameController()
	{
	}
} // namespace QtCha2P

