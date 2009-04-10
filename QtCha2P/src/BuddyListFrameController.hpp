#ifndef _QTCHA2P_BUDDYLISTFRAMECONTROLLER_HPP_
#define _QTCHA2P_BUDDYLISTFRAMECONTROLLER_HPP_

#include <map>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtGui/QListWidget>

#include "BuddyList.hpp"
#include "BuddyListFrame.hpp"

namespace QtCha2P
{
	class BuddyListFrameController : public QObject
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

		private:
			// BuddyListFrame
			BuddyListFrame* m_frame;		

			// list widget
			QListWidget* m_buddyList;

			// map to store buddy with its item
			std::map<QString, QListWidgetItem*> m_buddies;

		public:
			// ctor
			BuddyListFrameController();

			// dtor
			~BuddyListFrameController();

			// add Buddy
			void addBuddy(QString nickname);

			// remove Buddy
			void removeBuddy(QString nickname);
			
			// sync with internal buddylist
			void syncContactList(BuddyList* list);

		signals:
			void addNewPrivateTab(QString nickname);

		public slots:
			void onItemDoubleClicked(QListWidgetItem* item);

	}; // class BuddyListFrameController
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDYLISTFRAMECONTROLLER_HPP_

