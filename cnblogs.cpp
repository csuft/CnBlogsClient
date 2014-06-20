#include "cnblogs.h"
#include <QIcon>

cnblogs::cnblogs(QWidget *parent)
	: ShadowWindow(parent)
{
	setFixedSize(1024, 750);
	setWindowIcon(QIcon(":/syspic/trayicon"));


	
	m_systemtray = new SystemTray(this);
	m_systemtray->show();
}

cnblogs::~cnblogs()
{

}
