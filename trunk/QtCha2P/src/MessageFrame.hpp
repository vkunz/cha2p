#ifndef _QTCHA2P_MESSAGEFRAME_HPP_
#define _QTCHA2P_MESSAGEFRAME_HPP_

#include <QtGui/QFrame>
#include <QtGui/QTabWidget>

namespace QtCha2P
{
	class MessageFrame : public QFrame
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

		private:

		public:
			// ctor
			MessageFrame(QWidget* parent = 0);
			
			// dtor
			~MessageFrame();

	}; // class MessageFrame
} // namespace QtCha2P

#endif // _QTCHA2P_MESSAGEFRAME_HPP_

