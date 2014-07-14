#ifndef BEFORECLOSINGWIDGET_H
#define BEFORECLOSINGWIDGET_H

#include "BaseCtrl/shadowwindow.h"


class BeforeClosingWidget : public ShadowWindow
{
	Q_OBJECT

public:
	BeforeClosingWidget(QWidget *parent = 0);
	~BeforeClosingWidget();

private:

};

#endif // BEFORECLOSINGWIDGET_H
