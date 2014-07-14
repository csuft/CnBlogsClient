#include "cnblogs.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	int retVal;
	// 使用共享内存来保证程序单实例运行
	QSharedMemory sharedMemory("www.cnblogs.com");
	if (sharedMemory.create(1) && sharedMemory.error() != QSharedMemory::AlreadyExists)
	{
		
		QFile file(":/style/mainframe");
		file.open(QFile::ReadOnly);
		qApp->setStyleSheet(file.readAll());
		file.close();

		cnblogs win;
		win.show();
		retVal = app.exec();
	}
	else
	{
		QMessageBox::critical(NULL, "Critical Error", QStringLiteral("注意：博客园客户端程序已经运行！"), QMessageBox::Ok);
	}

	return retVal;
}
