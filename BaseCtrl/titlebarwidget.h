#ifndef TITLEBARWIDGET_H
#define TITLEBARWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "BaseCtrl/custompushbutton.h"
/*
 * The title bar widget includes system buttons, window title and a static text.
 * 
 */
class TitleBarWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TitleBarWidget(QWidget *parent);
	~TitleBarWidget();
	
private:
	void paintEvent(QPaintEvent* event);

signals:
	void minimizeClicked();
	void closeClicked();
	void skinChanged();

private:
	
	QHBoxLayout* m_topLayout;
	QHBoxLayout* m_mainLayout;

	CustomPushButton* m_miniBtn;
	CustomPushButton* m_closeBtn;

	QLabel* m_logo;
	QPushButton* m_about;
};

#endif // TITLEBARWIDGET_H
