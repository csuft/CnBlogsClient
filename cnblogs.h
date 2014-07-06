#ifndef CNBLOGS_H
#define CNBLOGS_H

#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QSignalMapper>
#include <QSettings>
#include <QPushButton>
#include <QMessageBox>
#include "shadowwindow.h"
#include "systemtray.h"
#include "customtoolbutton.h"
#include "nofocusdelegate.h"
#include "titlebarwidget.h"
#include "promptwindow.h"
#include "itemwidget.h"
#include "detailwindow.h"

class cnblogs : public ShadowWindow
{
	Q_OBJECT

public:
	cnblogs(QWidget *parent = 0);
	~cnblogs();

private slots:
	void onToolBtnClicked(const QString&);

private:
	void restoreSettings();
	void saveSettings();
	void setLoginTips();

private:
	TitleBarWidget* m_titleBar;
	QWidget* m_centralWidget;

	QVBoxLayout* m_leftLayout;
	QHBoxLayout* m_topLayout;
	QVBoxLayout* m_rightLayout;
	QGridLayout* m_bottomLayout;
	QVBoxLayout* m_mainLayout;

	QPushButton* m_refreshBtn;
	QPushButton* m_openWithIE;
	QPushButton* m_about;
	QPushButton* m_loginBtn;
	QListWidget* m_listWidget;
	QLabel* m_verinfo;
	QPushButton* m_settings;

	QList<CustomToolButton*> m_toolBtnList;

	SystemTray* m_systemtray;
};

#endif // CNBLOGS_H
