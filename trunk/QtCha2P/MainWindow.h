#ifndef _ATHOS_MAINWINDOW_H_
#define _ATHOS_MAINWINDOW_H_

#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass* ui;
};

#endif // _ATHOS_MAINWINDOW_H_
