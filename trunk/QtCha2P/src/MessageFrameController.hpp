#ifndef _QTCHA2P_MESSAGEFRAMECONTROLLER_HPP_
#define _QTCHA2P_MESSAGEFRAMECONTROLLER_HPP_

#include <map>
#include <QDebug>
#include <QtCore/QObject>
#include <QtGui/QTabWidget>

#include "Buddy.hpp"
#include "MessageFrame.hpp"
#include "MessageTab.hpp"

namespace QtCha2P
{
	class MessageFrameController : public QObject
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

		private:
			// frame to manage
			MessageFrame* m_frame;
			
			// message tab
			MessageTab* m_tab;
			
			// tab widget
			QTabWidget* m_widget;
			
			// map that stores tab index and buddy this tab belongs to
			std::map<unsigned int, Buddy> m_tabs;

		public:
			// ctor
			MessageFrameController();

			// dtor
			~MessageFrameController();
			
			// new private chat
			void addPrivateChatTab(Buddy buddy);
			
		signals:
			// this signal is emmited, when a new input text was typed in into the channel tab
			void newChannelMessage(QString message);
			
			// this signal is emmited, when a new input text was tpyed into an other tab
			void newPrivateMessage(Buddy buddy, QString message);
		
		public slots:
			// received new message from a tab
			void newInputMessage(QString inputMessage);

	}; // class MessageFrameController
} // namespace QtCha2P

#endif // _QTCHA2P_MESSAGEFRAMECONTROLLER_HPP_

