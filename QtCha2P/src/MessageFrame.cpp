
#include "MessageFrame.hpp"

namespace QtCha2P
{
	// ctor
	MessageFrame::MessageFrame(QWidget* parent) : QFrame(parent)
	{
		if (objectName().isEmpty())
		{
			setObjectName(QString::fromUtf8("MessageFrame"));	
		}
		
		// MessageFrame
		resize(650, 450);
		setMinimumSize(650, 450);
		setAcceptDrops(true);
		setFrameShape(QFrame::Box);
		setFrameShadow(QFrame::Raised);
		setWindowTitle(QString::fromUtf8("MessageFrame"));
	}
	
	// dtor
	MessageFrame::~MessageFrame()
	{
	}
} // namespace QtCha2P
