#include "titlebarwidget.h"

TitleBarWidget::TitleBarWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedHeight(80);
	m_mainLayout = new QHBoxLayout(this);
	m_topLayout = new QHBoxLayout(this);
	m_botLayout = new QHBoxLayout(this);
	
	m_logo = new QLabel(this);
	m_logo->setPixmap(QPixmap(":/syspic/logo"));
	m_logo->setFixedSize(QPixmap(":/syspic/logo").size());

	m_miniBtn = new CustomPushButton(this);
	m_closeBtn = new CustomPushButton(this);
	m_skinBtn = new CustomPushButton(this);
	m_miniBtn->setBtnBackground(":/syspic/mini_normal");
	m_miniBtn->setToolTip("缩小");
	m_closeBtn->setBtnBackground(":/syspic/close_normal");
	m_closeBtn->setToolTip("关闭");
	m_skinBtn->setBtnBackground(":/syspic/skin_normal");
	m_skinBtn->setToolTip("切换皮肤");

	m_about = new QPushButton("关于");
	m_about->setObjectName("about");
	
	m_topLayout->addWidget(m_logo, 0, Qt::AlignVCenter);
	m_topLayout->addStretch();
	m_topLayout->addWidget(m_miniBtn, 0, Qt::AlignTop);
	m_topLayout->addWidget(m_closeBtn, 0, Qt::AlignTop);

	m_topLayout->setSpacing(0);
	m_topLayout->setContentsMargins(10, 0, 0, 0);

	m_botLayout->addStretch();
	m_botLayout->addWidget(m_about, 0, Qt::AlignBottom);
	m_botLayout->setContentsMargins(0, 0, 10, 10);

	m_mainLayout->addLayout(m_topLayout);
	m_mainLayout->addLayout(m_botLayout);
	m_mainLayout->setSpacing(0);
	m_mainLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(m_mainLayout);

	// all events are handled by the main widget.
	connect(m_miniBtn, SIGNAL(clicked()), this, SIGNAL(minimizeClicked()));
	connect(m_closeBtn, SIGNAL(clicked()), this, SIGNAL(closeClicked()));
	connect(m_about, SIGNAL(clicked()), this, SIGNAL(aboutClicked()));
	connect(m_skinBtn, SIGNAL(clicked()), this, SIGNAL(skinChanged()));
}

TitleBarWidget::~TitleBarWidget()
{

}
