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
	
	m_loginResult = new QLabel(this);
	m_loginResult->setObjectName("loginResult");

	m_bottomCenter->addRow(new QLabel(QStringLiteral("用户名:"), this), m_nameEdit);
	m_bottomCenter->addRow(new QLabel(QStringLiteral("密码:"), this), m_pwdEdit);
	m_bottomCenter->addRow(m_checkBox, m_loginBtn);
	m_bottomCenter->addRow(m_loginResult);

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
	connect(m_checkBox, SIGNAL(toggled(bool)), this, SLOT(onCheckboxToggled(bool)));
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::onCloseClicked()
{
	this->accept();
}
/*
 * 绘制窗口背景，以图片代替
 */
void LoginDialog::paintEvent(QPaintEvent* e)
{
	ShadowWindow::paintEvent(e);

	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(5, 5, width()-10, height()-10, QPixmap(":/syspic/background"));
}

void LoginDialog::onLoginClicked()
{
	if (m_nameEdit->text().isEmpty() || m_pwdEdit->text().isEmpty())
	{
		m_loginResult->setText(QStringLiteral("注意：用户名和密码缺一不可！"));
	}
	else
	{
		m_loginThread = new HttpLogin(m_nameEdit->text().toStdString(), m_pwdEdit->text().toStdString());
		connect(m_loginThread, SIGNAL(finished()), this, SLOT(onThreadFinished()));
		m_loginResult->setText(QStringLiteral("正在登录..."));
		m_loginBtn->setDisabled(true);
		m_nameEdit->setDisabled(true);
		m_pwdEdit->setDisabled(true);
		// 启动线程进行登录
		m_loginThread->start();
	}
}

void LoginDialog::onCheckboxToggled(bool state)
{
	m_pwdEdit->setEchoMode(state?QLineEdit::Normal:QLineEdit::Password);
}

void LoginDialog::onThreadFinished()
{
	QString res = QString::fromStdString(m_loginThread->getState()); 
	if (res.isEmpty())
	{
		// 通知主窗口登录成功
		emit loginSucceed();
		this->accept();
	}
	else
	{
		m_nameEdit->setEnabled(true);
		m_pwdEdit->setEnabled(true);
		m_loginBtn->setEnabled(true);
		m_loginResult->setText(res);
	}
	QFile file(LOGIN_TEMP);
	if (file.exists())
	{
		file.remove();
	}
}