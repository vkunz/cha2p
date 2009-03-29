
#include <QtGui/QApplication>

#include "MainController.hpp"

int main(int argc, char *argv[])
{
	QApplication QtCha2P(argc, argv);
	QtCha2P::MainController mc;
	return QtCha2P.exec();
}
