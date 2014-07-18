#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "BaseCtrl/shadowwindow.h"
#include "BaseCtrl/custompushbutton.h"

class LoginDialog : public ShadowWindow
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent);
	~LoginDialog();

signals:
	void userLogin(const QString& name, const QString& passwd);

private slots:
	void onCloseClicked();

protected:
	void paintEvent(QPaintEvent* e);

private:
	//430 290
	QPushButton* m_loginBtn;
	QCheckBox* m_checkBox;
	QLineEdit* m_pwdEdit;
	QLineEdit* m_nameEdit;
	QLabel* m_infoLabel;
	CustomPushButton* m_closeBtn;

	QHBoxLayout* m_topLayout;
	QHBoxLayout* m_bottomLayout;
	QVBoxLayout* m_mainLayout;
	QFormLayout* m_bottomCenter;
};

#endif // LOGINDIALOG_H
