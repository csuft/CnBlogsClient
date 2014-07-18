#include "logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
	: ShadowWindow(parent)
{
	setFixedSize(430, 290);

	m_mainLayout = new QVBoxLayout(this);
	m_topLayout = new QHBoxLayout(this);
	m_bottomCenter = new QFormLayout(this);
	m_bottomLayout = new QHBoxLayout(this);

	m_infoLabel = new QLabel(QStringLiteral("博客园用户登录"), this);
	m_infoLabel->setObjectName("loginTitle");
	m_closeBtn = new CustomPushButton(this);
	m_closeBtn->setBtnBackground(":/syspic/close");
	m_topLayout->addWidget(m_infoLabel, 0,Qt::AlignCenter);
	m_topLayout->addWidget(m_closeBtn, 0, Qt::AlignTop);
	m_topLayout->setContentsMargins(10, 0, 0, 5);

	m_nameEdit = new QLineEdit(this);
	m_nameEdit->setPlaceholderText(QStringLiteral("博客园用户名"));
	m_nameEdit->setFixedSize(120, 25);

	m_pwdEdit = new QLineEdit(this);
	m_pwdEdit->setPlaceholderText(QStringLiteral("博客园密码"));
	m_pwdEdit->setEchoMode(QLineEdit::Password);
	m_pwdEdit->setFixedSize(120, 25);

	m_checkBox = new QCheckBox(QStringLiteral("显示明文密码"), this);
	m_loginBtn = new QPushButton(QStringLiteral("登录"), this);
	m_loginBtn->setObjectName("loginBtn");
	m_loginBtn->setFixedSize(120, 25);

	m_bottomCenter->addRow(new QLabel(QStringLiteral("用户名:"), this), m_nameEdit);
	m_bottomCenter->addRow(new QLabel(QStringLiteral("密码:"), this), m_pwdEdit);
	m_bottomCenter->addRow(m_checkBox, m_loginBtn);

	m_bottomLayout->addStretch();
	m_bottomLayout->addLayout(m_bottomCenter);
	m_bottomLayout->addStretch();

	QWidget* bottomWidget = new QWidget(this);
	bottomWidget->setObjectName("bottomWidget");
	bottomWidget->setLayout(m_bottomLayout);

	m_mainLayout->addLayout(m_topLayout);
	m_mainLayout->addWidget(bottomWidget);
	m_mainLayout->setSpacing(0);
	m_mainLayout->setContentsMargins(5, 5, 5, 5);

	setLayout(m_mainLayout);
	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(onCloseClicked()));
	connect(m_loginBtn, SIGNAL(clicked()), this, SLOT(onLoginClicked()));
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::onCloseClicked()
{
	this->accept();
}

void LoginDialog::paintEvent(QPaintEvent* e)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(5, 5, width()-10, height()-10, QPixmap(":/syspic/background"));
}

void LoginDialog::onLoginClicked()
{
	
}