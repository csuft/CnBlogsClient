#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
	: ShadowWindow(parent)
{
	setFixedSize(400, 300);
	m_mainLayout = new QVBoxLayout(this);
	m_topLayout = new QHBoxLayout(this);

	m_closeBtn = new CustomPushButton(this);
	m_closeBtn->setBtnBackground(":/syspic/close");
	m_title = new QLabel(QStringLiteral("程序设置"), this);
	m_title->setObjectName("title");
	m_topLayout->addWidget(m_title, 0, Qt::AlignLeft | Qt::AlignVCenter);
	m_topLayout->addWidget(m_closeBtn, 0, Qt::AlignTop | Qt::AlignRight);
	m_topLayout->setContentsMargins(5, 0, 0, 5);

	m_widget = new QWidget(this);

	m_mainLayout->addLayout(m_topLayout);
	m_mainLayout->addWidget(m_widget, 1);
	m_mainLayout->setSpacing(0);
	m_mainLayout->setContentsMargins(5, 5, 5, 5);

	setLayout(m_mainLayout);

	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(accept()));
}

SettingsWidget::~SettingsWidget()
{

}

