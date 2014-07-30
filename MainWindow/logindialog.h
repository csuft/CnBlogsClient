#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFile>

#include "BaseCtrl/shadowwindow.h"
#include "BaseCtrl/custompushbutton.h"
#include "Network/HttpClient.h"
#include "Network/Commons.h"

/*
 * 登录窗口
 */ 
class LoginDialog : public ShadowWindow
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = NULL);
	~LoginDialog();

signals:
	void userLogin(const QString& name, const QString& passwd);
	void loginSucceed();

private slots:
	void onCloseClicked();
	void onLoginClicked();
	void onCheckboxToggled(bool state);
	void onThreadFinished();

protected:
	void paintEvent(QPaintEvent* e);

private:
	//430 290
	QPushButton* m_loginBtn;
	QCheckBox* m_checkBox;
	QLineEdit* m_pwdEdit;
	QLineEdit* m_nameEdit;
	QLabel* m_infoLabel;
	QLabel* m_loginResult;
	CustomPushButton* m_closeBtn;

	HttpLogin* m_loginThread;

	QHBoxLayout* m_topLayout;
	QHBoxLayout* m_bottomLayout;
	QVBoxLayout* m_mainLayout;
	QFormLayout* m_bottomCenter;
};

#endif // LOGINDIALOG_H
