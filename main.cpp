#include "cnblogs.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QFile file(":/style/mainframe");
	file.open(QFile::ReadOnly);
	qApp->setStyleSheet(file.readAll());
	file.close();

	cnblogs win;
	win.show();
	return app.exec();
}
