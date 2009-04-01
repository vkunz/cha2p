#ifndef _QTCHA2P_BUDDYLISTFRAMECONTROLLER_HPP_
#define _QTCHA2P_BUDDYLISTFRAMECONTROLLER_HPP_

#include <map>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtGui/QListWidget>

#include "BuddyListFrame.hpp"

namespace QtCha2P
{
	class BuddyListFrameController : public QObject
	{
		private:
			// BuddyListFrame
			BuddyListFrame* m_frame;		

			// list widget
			QListWidget* m_buddylist;

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

		signals:
			void addNewPrivateTab(QString nickname);

		public slots:
			void onItemDoubleClicked(QListWidgetItem*);

	}; // class BuddyListFrameController
} // namespace QtCha2P

#endif // _QTCHA2P_BUDDYLISTFRAMECONTROLLER_HPP_

