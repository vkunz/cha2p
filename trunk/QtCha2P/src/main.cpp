#include <QtGui/QApplication>

#include "MainWindow.hpp"
#include "LogInWindow.hpp"

int main(int argc, char *argv[])
{
	QApplication QtCha2P(argc, argv);
	QtCha2P::LogInWindow liw;
	liw.show();
	return QtCha2P.exec();
}
