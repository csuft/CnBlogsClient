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
#include <QTimer>
#include <QDateTime>
#include <QtWebKitWidgets/QWebView>
#include "shadowwindow.h"
#include "systemtray.h"
#include "customtoolbutton.h"
#include "nofocusdelegate.h"
#include "titlebarwidget.h"
#include "promptwindow.h"

class cnblogs : public ShadowWindow
{
	Q_OBJECT

public:
	cnblogs(QWidget *parent = 0);
	~cnblogs();

private slots:
	void onToolBtnClicked(const QString&);
	void onZoomClicked();

private:
	void restoreSettings();
	void saveSettings();
	void setLoginTips();
	void changePage(int index);

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
	QWebView* m_webView;
	QPushButton* m_zoomBtn;
	QLabel* m_verinfo;
	QPushButton* m_settings;
	QTimer* m_gtimer;

	QList<CustomToolButton*> m_toolBtnList;

	SystemTray* m_systemtray;
	bool flag;
};

#endif // CNBLOGS_H
