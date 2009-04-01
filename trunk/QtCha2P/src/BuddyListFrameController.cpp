#include <QtGui/QListWidget>

#include "BuddyListFrame.hpp"
#include "BuddyListFrameController.hpp"

namespace QtCha2P
{
	// ctor
	BuddyListFrameController::BuddyListFrameController()
	{
		// new frame
		m_frame = new BuddyListFrame();

		// new listitem
		m_buddylist = new QListWidget(m_frame);

		// set object name
		m_buddylist->setObjectName(QString::fromUtf8("Buddies"));

		// set Geometry
		m_buddylist->setGeometry(QRect(0, 0, 200, 600));

		// connect doubleclicked with slot onItemDoubleClicked()
		connect(m_buddylist, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onItemDoubleClicked(QListWidgetItem*)));

		// show frame
		m_frame->show();
	}

	// dtor
	BuddyListFrameController::~BuddyListFrameController()
	{	
	}

	// add Buddy
	void BuddyListFrameController::addBuddy(QString nickname)
	{
		// new item
		QListWidgetItem* newItem = new QListWidgetItem();

		// set text
		newItem->setText(nickname);

		// add into map
		m_buddies.insert(std::pair<QString, QListWidgetItem*>(nickname, newItem));

		// add item
		m_buddylist->addItem(nickname);
	}

	// remove Buddy
	void BuddyListFrameController::removeBuddy(QString nickname)
	{
		// tmp iterator
		std::map<QString, QListWidgetItem*>::iterator it;

		// remove item
		m_buddylist->removeItemWidget(m_buddies[nickname]);
	}

	// slot: onItemDoubleClicked(QListWidgetItem*)
	void BuddyListFrameController::onItemDoubleClicked(QListWidgetItem* item)
	{
		// get text
		QString tmp = item->text();

		// todo
	}
} // namespace QtCha2P
