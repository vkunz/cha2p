#include <QtGui/QListWidget>

#include "BuddyListFrame.hpp"

namespace QtCha2P
{
	// ctor
	BuddyListFrame::BuddyListFrame(QWidget* parent) : QFrame(parent)
	{
		if(objectName().isEmpty())
		{
			setObjectName(QString::fromUtf8("BuddyListFrame"));
		}
		
		// set title
		setWindowTitle(QString::fromUtf8("BuddyList"));
		
		// resize window
		resize(200, 600);
		
		// set minsize
		setMinimumSize(200, 600);
		
		// set maxsize
		setMaximumSize(200, 600);
	}
	
	// dtor
	BuddyListFrame::~BuddyListFrame()
	{
	}
} // namespace QtCha2P
