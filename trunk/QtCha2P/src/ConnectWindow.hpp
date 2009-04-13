#ifndef _QTCHA2P_CONNECTWINDOW_HPP_
#define _QTCHA2P_CONNECTWINDOW_HPP_

#include <QtGui/QAction>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

namespace QtCha2P
{
	class ConnectWindow : public QMainWindow
	{
		// QtMeta-Object-Compiler tags
		Q_OBJECT

	private:
		// attributes
		QAction*		m_actionExit;
		QLabel*			m_lblChannel;
		QLabel*			m_lblConnect;
		QLabel*			m_lblNickname;
		QLineEdit*		m_lneChannel;
		QLineEdit*		m_lneConnect;
		QLineEdit*		m_lneNickname;
		QMenu*			m_menuFile;
		QMenuBar*		m_menubar;
		QPushButton*	m_btnConnect;
		QStatusBar*		m_statusbar;
		QWidget*		m_centralwidget;
		
	public:
		// ctor
		ConnectWindow(QWidget *parent = 0);
	
		// dtor
		~ConnectWindow();
	
	signals:
		void requestContactList(QString host, QString nickname);
			
	public slots:
		void onBtnConnectPressed();

	}; // class ConnectWindow
} // namespace QtCha2P

#endif // _QTCHA2P_CONNECTWINDOW_HPP

