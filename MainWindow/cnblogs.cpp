#include "cnblogs.h"

cnblogs::cnblogs(QWidget *parent)
	: ShadowWindow(parent)
{
	setFixedSize(1024, 750);
	setWindowIcon(QIcon(":/syspic/trayicon"));
	flag = false;
	isLogin = false;

	m_mainLayout = new QVBoxLayout(this);
	m_topLayout = new QHBoxLayout(this);
	m_bottomLayout = new QGridLayout(this);
	m_leftLayout = new QVBoxLayout(this);
	m_rightLayout = new QVBoxLayout(this);

	// top title widget
	m_titleBar = new TitleBarWidget(this);

	// left button list widget
	QStringList strList;
	strList << ":/panelbutton/home" << ":/panelbutton/essence" << ":/panelbutton/alternative"
		<< ":/panelbutton/news" << ":/panelbutton/myblog" << ":/panelbutton/recommend"
		<< ":/panelbutton/comment" << ":/panelbutton/preference" << ":/panelbutton/setting";
	QStringList textList;
	textList << QStringLiteral("首页") << QStringLiteral("精华") << QStringLiteral("候选博文") 
			 << QStringLiteral("新闻") << QStringLiteral("我的博客") << QStringLiteral("推荐博客")
			 << QStringLiteral("我评") << QStringLiteral("我赞") << QStringLiteral("系统设置");
	QSignalMapper* sigMapper = new QSignalMapper(this);
	for (int i = 0; i < strList.size(); ++i)
	{
		// create a custom tool button
		CustomToolButton* tmpBtn = new CustomToolButton(strList.at(i), this);
		connect(tmpBtn, SIGNAL(clicked()), sigMapper, SLOT(map()));
		// set tool buttons' text
		tmpBtn->setText(textList.at(i));
		m_toolBtnList.append(tmpBtn);
		// establish a mapping between the string and widget pointer.
		sigMapper->setMapping(tmpBtn, QString::number(i, 10));
		m_leftLayout->addWidget(tmpBtn);

	}
	m_leftLayout->setSpacing(5);
	m_leftLayout->setContentsMargins(0, 0, 0, 0);

	// top layout
	m_refreshBtn = new QPushButton(QIcon(":/panelbutton/refresh"), QStringLiteral("刷新"), this);
	m_refreshBtn->setObjectName("refresh");
	m_openWithIE = new QPushButton(QIcon(":/panelbutton/browser"), QStringLiteral("打开浏览器"), this);
	m_openWithIE->setObjectName("open");
	m_loginBtn = new QPushButton(QIcon(":/panelbutton/login"), QStringLiteral("立即登录"), this);
	m_loginBtn->setToolTip(QStringLiteral("用博客园账户登录"));
	m_loginBtn->setObjectName("login");
	m_about = new QPushButton(QIcon(":/panelbutton/about"), QStringLiteral("关于"), this);
	m_about->setObjectName("about");
	m_topLayout->addWidget(m_refreshBtn);
	m_topLayout->addWidget(m_openWithIE);
	m_topLayout->addStretch();
	m_topLayout->addWidget(m_about);
	m_topLayout->addWidget(m_loginBtn);
	m_topLayout->addSpacing(0);
	m_topLayout->setContentsMargins(5, 0, 5, 0);

	// right layout
	m_stackedWidget = new CStackedWidget(this);
	QWidget* webContainer = new QWidget(this);
	m_webView = new QWebView(webContainer);
	m_webView->load(QUrl("http://www.cnblogs.com/fangjian0423/p/3808176.html"));
	m_webView->setFixedWidth(880);
	m_webView->setFixedHeight(545);
	m_webView->setZoomFactor(0.85);
	m_zoomBtn = new QPushButton(this);
	m_zoomBtn->setIcon(QIcon(":/panelbutton/up"));
	m_zoomBtn->setCursor(Qt::PointingHandCursor);
	m_zoomBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_zoomBtn->setFixedHeight(7);
	m_zoomBtn->setFocusPolicy(Qt::NoFocus);
	m_zoomBtn->setObjectName("zoomBtn");
	m_zoomBtn->setToolTip(QStringLiteral("收起列表"));
	//m_verinfo = new QLabel(QStringLiteral("启动时间: ") + QDateTime::currentDateTime().toString("yyyy-MM-d H:m:ss AP"), this);
	m_verinfo = new QLabel(QStringLiteral("<a href='http://www.cnblogs.com/csuftzzk'>打开博客园</a>"), this);
	m_verinfo->setOpenExternalLinks(true);
	m_verinfo->setObjectName("versionLabel");
	m_rightLayout->addWidget(m_stackedWidget, 1);
	m_rightLayout->addWidget(m_zoomBtn);
	m_rightLayout->addWidget(webContainer, 1);
	m_rightLayout->addWidget(m_verinfo, 0, Qt::AlignRight);
	m_rightLayout->setSpacing(0);
	m_rightLayout->setContentsMargins(0, 0, 0, 0);

	// bottom layout
	m_bottomLayout->addLayout(m_leftLayout, 1, 0);
	m_bottomLayout->addLayout(m_topLayout, 0, 1);
	m_bottomLayout->addLayout(m_rightLayout, 1, 1);
	m_bottomLayout->setColumnStretch(0, 20);
	m_bottomLayout->setColumnStretch(1, 30);
	m_bottomLayout->setContentsMargins(10, 0, 20, 0);
	m_bottomLayout->setColumnMinimumWidth(0, 100);
	
	// main layout for the window
	m_mainLayout->addWidget(m_titleBar);
	m_mainLayout->addLayout(m_bottomLayout);
	m_mainLayout->setSpacing(5);
	m_mainLayout->setContentsMargins(5, 5, 5, 25);
	setLayout(m_mainLayout);

	// system tray
	m_systemtray = new SystemTray(this);
	m_systemtray->show();

	// click the first tab 
	onToolBtnClicked(QString::number(0));

	connect(sigMapper, SIGNAL(mapped(const QString&)), this, SLOT(onToolBtnClicked(const QString&)));
	connect(m_titleBar, SIGNAL(minimizeClicked()), this, SLOT(showMinimized()));
	connect(m_titleBar, SIGNAL(closeClicked()), this, SLOT(close()));
	connect(m_zoomBtn, SIGNAL(clicked()), this, SLOT(onZoomClicked()));
	connect(this, SIGNAL(changePage(int)), m_stackedWidget, SLOT(onWidgetsChoosed(int)));
	connect(m_refreshBtn, SIGNAL(clicked()), this, SLOT());
	connect(m_openWithIE, SIGNAL(clicked()), this, SLOT());
	connect(m_loginBtn, SIGNAL(clicked()), this, SLOT());
	connect(m_about, SIGNAL(clicked()), this, SLOT());
}

cnblogs::~cnblogs()
{

}


void cnblogs::onToolBtnClicked(const QString& obj)
{
	int index = obj.toInt();

	for (int i = 0; i < m_toolBtnList.count(); ++i)
	{
		CustomToolButton* tmpBtn = m_toolBtnList.at(i);
		// normalize all tool buttons except the one the user clicked.
		tmpBtn->setButtonPressed(i==index);
	}
	// While switching diefferent widgets for other tool buttons, 
	// we show a dialog for the settings button.
	if (index < 8)
	{
		emit changePage(index);
	}
	else
	{
		SettingsWidget settings;
		settings.exec();
	}

}
/*
 * Restore all settings when the program runs
 */
void cnblogs::restoreSettings()
{

}
/*
 * Save all user personal settings
 */
void cnblogs::saveSettings()
{

}

void cnblogs::onZoomClicked()
{
	if (flag)
	{
		flag = false;
		m_zoomBtn->setIcon(QIcon(":/panelbutton/up"));
		m_stackedWidget->setVisible(true);
		m_zoomBtn->setToolTip(QStringLiteral("收起列表"));
	}
	else
	{
		flag = true;
		m_zoomBtn->setIcon(QIcon(":/panelbutton/down"));
		m_stackedWidget->setVisible(false);
		m_zoomBtn->setToolTip(QStringLiteral("展开列表"));
	}

}

void cnblogs::onRefreshClicked()
{
	QMessageBox::information(this, "Tips", "Not implemented yet...");
}

void cnblogs::onOpenWithIEClicked()
{
	QMessageBox::information(this, "Tips", "Not implemented yet...");

}

void cnblogs::onLoginClicked()
{
	LoginDialog* loginDlg = new LoginDialog(this);
	loginDlg->exec();
}

void cnblogs::onAboutClicked()
{
	QMessageBox::information(this, "Tips", "Not implemented yet...");
}