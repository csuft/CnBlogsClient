#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
	: ShadowWindow(parent)
{
	setFixedSize(360, 250);
	m_mainLayout = new QVBoxLayout(this);
	m_topLayout = new QHBoxLayout(this);
	m_bottomLayout = new QVBoxLayout(this);
	
	m_closeBtn = new CustomPushButton(this);
	m_closeBtn->setBtnBackground(":/syspic/close");
	m_icon = new QLabel(this);
	m_icon->setPixmap(QPixmap(":/syspic/24k"));
	m_desc = new QLabel(QStringLiteral("<b>博客园PC客户端 v1.0</b> 开发者：24K纯开源"), this);
	m_dev = new QLabel(QStringLiteral("博客: <a href='http://www.cnblogs.com/csuftzzk'>http://www.cnblogs.com/csuftzzk</a>"), this);
	m_github = new QLabel(QStringLiteral("我的Github: <a href='https://github.com/csuft'>https://github.com/csuft</a>"), this);

	m_topLayout->addWidget(m_closeBtn, 0,  Qt::AlignTop|Qt::AlignRight);
	m_closeBtn->setContentsMargins(0, 0, 0, 0);

	QWidget* container = new QWidget(this);
	container->setFixedHeight(80);
	container->setObjectName("container");
	m_bottomLayout->addWidget(m_desc, 0, Qt::AlignCenter);
	m_bottomLayout->addWidget(m_dev, 0, Qt::AlignCenter);
	m_bottomLayout->addWidget(m_github, 0, Qt::AlignCenter);
	m_bottomLayout->setSpacing(5);
	container->setLayout(m_bottomLayout);

	m_mainLayout->addLayout(m_topLayout);
	m_mainLayout->addWidget(m_icon, 0, Qt::AlignTop|Qt::AlignHCenter);
	m_mainLayout->addWidget(container);
	m_mainLayout->setSpacing(5);
	m_mainLayout->setContentsMargins(5,5,5,5);

	setLayout(m_mainLayout);
	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(accept()));
}

AboutDialog::~AboutDialog()
{

}

void AboutDialog::paintEvent(QPaintEvent* event)
{
	ShadowWindow::paintEvent(event);

	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(5, 5, width()-10, height()-10, QPixmap(":/syspic/background"));
}
