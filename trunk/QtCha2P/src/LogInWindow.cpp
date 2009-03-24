#include "LogInWindow.hpp"
#include "ui_LogInWindow.h"

namespace QtCha2P
{
	LogInWindow::LogInWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::LogInWindowClass)
	{
		ui->setupUi(this);
	}

	LogInWindow::~LogInWindow()
	{
		delete ui;
	}
} // namespaace QtCha2P
