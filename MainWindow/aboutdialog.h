#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "BaseCtrl/shadowwindow.h"
#include "BaseCtrl/custompushbutton.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class AboutDialog : public ShadowWindow
{
	Q_OBJECT

public:
	AboutDialog(QWidget *parent = NULL);
	~AboutDialog();

protected:
	void paintEvent(QPaintEvent* event);

private:
	CustomPushButton* m_closeBtn;
	QLabel* m_icon;
	QLabel* m_desc;
	QLabel* m_dev;
	QLabel* m_github;

	QVBoxLayout* m_mainLayout;
	QHBoxLayout* m_topLayout;
	QVBoxLayout* m_bottomLayout;
};

#endif // ABOUTDIALOG_H
