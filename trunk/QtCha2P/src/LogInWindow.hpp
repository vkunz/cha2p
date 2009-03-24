#ifndef _QTCHA2P_LOGINWINDOW_H_
#define _QTCHA2P_LOGINWINDOW_H_

#include <QtGui/QMainWindow>

namespace Ui
{
    class LogInWindowClass;
} // namespace Ui

namespace QtCha2P
{
	class LogInWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		LogInWindow(QWidget *parent = 0);
		~LogInWindow();

	private:
		Ui::LogInWindowClass* ui;
	}; // class LogInWindow
} // namespace QtCha2P

#endif // _QTCHA2P_LOGINWINDOW_H_
