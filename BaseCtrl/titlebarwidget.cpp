#include "titlebarwidget.h"

TitleBarWidget::TitleBarWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedHeight(100);
	m_mainLayout = new QHBoxLayout(this);
	m_topLayout = new QHBoxLayout(this);
	
	m_logo = new QLabel(this);
	m_logo->setPixmap(QPixmap(":/syspic/logo"));
	m_logo->setFixedSize(QPixmap(":/syspic/logo").size());

	m_miniBtn = new CustomPushButton(this);
	m_closeBtn = new CustomPushButton(this);
	m_miniBtn->setBtnBackground(":/syspic/mini");
	m_miniBtn->setToolTip(QStringLiteral("缩小"));
	m_closeBtn->setBtnBackground(":/syspic/close");
	m_closeBtn->setToolTip(QStringLiteral("退出"));
	
	m_topLayout->addWidget(m_logo, 0, Qt::AlignVCenter);
	m_topLayout->addStretch(0);
	m_topLayout->addWidget(m_miniBtn, 0, Qt::AlignTop);
	m_topLayout->addWidget(m_closeBtn, 0, Qt::AlignTop);

	m_topLayout->setSpacing(0);
	m_topLayout->setContentsMargins(10, 0, 5, 0);

	m_mainLayout->addLayout(m_topLayout);
	m_mainLayout->setSpacing(0);
	m_mainLayout->setContentsMargins(15, 5, 5, 0);
	setLayout(m_mainLayout);

	// all events are handled by the main widget.
	connect(m_miniBtn, SIGNAL(clicked()), this, SIGNAL(minimizeClicked()));
	connect(m_closeBtn, SIGNAL(clicked()), this, SIGNAL(closeClicked()));
}

TitleBarWidget::~TitleBarWidget()
{

}

void TitleBarWidget::paintEvent(QPaintEvent* event)
{
	// draw the background using the specified image.
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(5, 5, width()-10, height()-10, QPixmap(":/syspic/background"));
}