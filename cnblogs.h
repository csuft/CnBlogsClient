#ifndef CNBLOGS_H
#define CNBLOGS_H

#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QSignalMapper>
#include <QSettings>;
#include "shadowwindow.h"
#include "systemtray.h"
#include "customtoolbutton.h"
#include "titlebarwidget.h"

class cnblogs : public ShadowWindow
{
	Q_OBJECT

public:
	cnblogs(QWidget *parent = 0);
	~cnblogs();

private:
	TitleBarWidget* m_titleBar;
	QWidget* m_centralWidget;

	QVBoxLayout* m_leftLayout;
	QVBoxLayout* m_rightLayout;
	QHBoxLayout* m_topLayout;
	QHBoxLayout* m_mainLayout;

	QPushButton* m_refreshBtn;
	QPushButton* m_openWithIE;
	QPushButton* m_loginBtn;
	QListWidget* m_listWidget;

	QList<CustomToolButton*> m_toolBtnList;

	SystemTray* m_systemtray;
};

#endif // CNBLOGS_H
