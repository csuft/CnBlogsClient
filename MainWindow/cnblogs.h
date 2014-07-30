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
#include <QStackedWidget>
#include <QDateTime>
#include <QtWebKitWidgets/QWebView>

#include "BaseCtrl/shadowwindow.h"
#include "BaseCtrl/systemtray.h"
#include "BaseCtrl/customtoolbutton.h"
#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/titlebarwidget.h"
#include "BaseCtrl/beforeclosingwidget.h"
#include "BaseCtrl/settingswidget.h"

#include "promptwindow.h"
#include "cstackedwidget.h"
#include "aboutdialog.h"
#include "logindialog.h"

class cnblogs : public ShadowWindow
{
	Q_OBJECT

public:
	cnblogs(QWidget *parent = 0);
	~cnblogs();

private slots:
	void onToolBtnClicked(const QString&);
	void onZoomClicked();
	void onRefreshClicked();
	void onOpenWithIEClicked();
	void onLoginClicked();
	void onAboutClicked();
	void onLoginSucceed();

private:
	void restoreSettings();
	void saveSettings();

signals:
	void changePage(int index);

private:
	// main window elements
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
	CStackedWidget* m_stackedWidget;
	QWebView* m_webView;
	QPushButton* m_zoomBtn;
	QLabel* m_verinfo;
	QPushButton* m_settings;
	QTimer* m_gtimer;

	QList<CustomToolButton*> m_toolBtnList;

	SystemTray* m_systemtray;
	bool flag;		 // 控制列表是否展开
	bool isLogin;    // 是否已经登录
};

#endif // CNBLOGS_H
