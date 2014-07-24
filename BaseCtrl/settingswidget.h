#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "shadowwindow.h"
#include "custompushbutton.h"

class SettingsWidget : public ShadowWindow
{
	Q_OBJECT

public:
	SettingsWidget(QWidget *parent = 0);
	~SettingsWidget();

private:
	CustomPushButton* m_closeBtn;
	QWidget* m_widget;
	QLabel* m_title;
	QHBoxLayout* m_topLayout;
	QVBoxLayout* m_mainLayout;
};

#endif // SETTINGSWIDGET_H
