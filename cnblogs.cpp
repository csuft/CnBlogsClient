#include "cnblogs.h"
#include <QIcon>

cnblogs::cnblogs(QWidget *parent)
	: ShadowWindow(parent)
{
	setFixedSize(1024, 750);
	setWindowIcon(QIcon(":/syspic/trayicon"));

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
	m_listWidget = new QListWidget(this);
	m_listWidget->setItemDelegate(new NoFocusDelegate());
	m_verinfo = new QLabel(this);
	m_rightLayout->addWidget(m_listWidget, 1);
	m_rightLayout->addWidget(m_verinfo, 0, Qt::AlignRight);
	m_rightLayout->setSpacing(5);
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

	connect(sigMapper, SIGNAL(mapped(const QString&)), this, SLOT(onToolBtnClicked(const QString&)));
	connect(m_titleBar, SIGNAL(minimizeClicked()), this, SLOT(showMinimized()));
	connect(m_titleBar, SIGNAL(closeClicked()), this, SLOT(close()));
}

cnblogs::~cnblogs()
{

}


void cnblogs::onToolBtnClicked(const QString&)
{


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

void cnblogs::setLoginTips()
{

}

