#include <QtGui/QSizePolicy>

#include "ConnectWindow.hpp"

namespace QtCha2P
{
	// ctor
	ConnectWindow::ConnectWindow(QWidget* parent) : QMainWindow(parent)
	{
		// set object name
		if (objectName().isEmpty())
		{
			setObjectName(QString::fromUtf8("LogInWindowClass"));
		}

		// QWidget: centralwidget
		m_centralwidget = new QWidget(this);
		m_centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		
		// QAction: exit
		m_actionExit = new QAction(this);
		m_actionExit->setObjectName(QString::fromUtf8("actionExit"));
		m_actionExit->setText(QString::fromUtf8("Exit"));
		
		// QLabel: nickname
		m_lblNickname = new QLabel(m_centralwidget);
		m_lblNickname->setObjectName(QString::fromUtf8("m_lblNickname"));
		m_lblNickname->setGeometry(QRect(20, 100, 70, 26));
		m_lblNickname->setText(QString::fromUtf8("Nickname:"));
		
		// QLabel: connect
		m_lblConnect = new QLabel(m_centralwidget);
		m_lblConnect->setObjectName(QString::fromUtf8("m_lblConnect"));
		m_lblConnect->setGeometry(QRect(20, 40, 60, 26));
		m_lblConnect->setText(QString::fromUtf8("Connect:"));

		// QLineEdit: connect
		m_lneConnect = new QLineEdit(m_centralwidget);
        m_lneConnect->setObjectName(QString::fromUtf8("m_lneConnect"));
        m_lneConnect->setGeometry(QRect(130, 40, 120, 26));
        m_lneConnect->setInputMask("000.000.000.000;_");
        
        // QLineEdit: nickname
        m_lneNickname = new QLineEdit(m_centralwidget);
        m_lneNickname->setObjectName(QString::fromUtf8("m_lneNickname"));
        m_lneNickname->setGeometry(QRect(130, 100, 120, 26));
        
        // QMenuBar:
        m_menubar = new QMenuBar(this);
		m_menubar->setObjectName(QString::fromUtf8("menubar"));
		m_menubar->setGeometry(QRect(0, 0, 300, 25));

		// QMenu: file
		m_menuFile = new QMenu(m_menubar);
        m_menuFile->setObjectName(QString::fromUtf8("menuFile"));
		m_menuFile->setTitle(QString::fromUtf8("File"));
		
		// QPushButton: connect
		m_btnConnect = new QPushButton(m_centralwidget);
		m_btnConnect->setObjectName(QString::fromUtf8("m_btnConnect"));
		m_btnConnect->setGeometry(QRect(105, 170, 90, 30));
		m_btnConnect->setText(QString::fromUtf8("Connect"));
        				
		// QSizePolicy
		QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());

		// QStatusBar:
		m_statusbar = new QStatusBar(this);
		m_statusbar->setObjectName(QString::fromUtf8("statusbar"));

		// menubar add action
		m_menubar->addAction(m_menuFile->menuAction());
		
		// menu add action
		m_menuFile->addAction(m_actionExit);

        // QMainWindow
        //setWindowModality(Qt::ApplicationModal);
        setEnabled(true);
        resize(300, 300);
		setSizePolicy(sizePolicy);
		setMinimumSize(QSize(300, 300));
		setMaximumSize(QSize(300, 300));
		setDocumentMode(false);
        setCentralWidget(m_centralwidget);
        setMenuBar(m_menubar);
        setStatusBar(m_statusbar);
        setWindowTitle("LogIn");
        
        // connect slots and signals
        QObject::connect(m_btnConnect, SIGNAL(pressed()), this, SLOT(onBtnConnectPressed()));
	}

	// dtor
	ConnectWindow::~ConnectWindow()
	{
	}
	
	// public slots
	void ConnectWindow::onBtnConnectPressed()
	{
		// tmp strings
		QString host, nick;

		// store host
		host = m_lneConnect->text();
		
		// store nick
		nick = m_lneNickname->text();
		
		// emit signal
		emit connect(host, nick);
	}
} // namespaace QtCha2P

