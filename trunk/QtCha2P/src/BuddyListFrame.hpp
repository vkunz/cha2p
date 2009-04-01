#ifndef _QTCHA2P_BUDDYLISTFRAME_HPP_
#define _QTCHA2P_BUDDYLISTFRAME_HPP_

#include <QtGui/QFrame>
#include <QtGui/QListWidget>

namespace QtCha2P
{
	class BuddyListFrame : public QFrame
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

	private:

	public:
		// ctor
		BuddyListFrame(QWidget* parent = 0);
		
		// dtor
		~BuddyListFrame();

	}; // class BuddyListFrame
} // namespace QtCha2P
#endif // _QTCHA2P_BUDDYLISTFRAME_HPP_
