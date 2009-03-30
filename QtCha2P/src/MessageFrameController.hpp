#ifndef _QTCHA2P_MESSAGEFRAMECONTROLLER_HPP_
#define _QTCHA2P_MESSAGEFRAMECONTROLLER_HPP_

#include <QtCore/QObject>
#include <QtGui/QTabWidget>

#include "MessageFrame.hpp"

namespace QtCha2P
{
	class MessageFrameController : public QObject
	{
		private:
			// frame to manage
			MessageFrame* m_frame;
			
			// tab widget
			QTabWidget* m_widget;

		public:
			// ctor
			MessageFrameController();

			// dtor
			~MessageFrameController();

	}; // class MessageFrameController
} // namespace QtCha2P

#endif // _QTCHA2P_MESSAGEFRAMECONTROLLER_HPP_

