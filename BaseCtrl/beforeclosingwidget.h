#ifndef BEFORECLOSINGWIDGET_H
#define BEFORECLOSINGWIDGET_H

#include "BaseCtrl/shadowwindow.h"

/*
 * To make sure whether the user wants to quit or clicked unintentional.
 */
class BeforeClosingWidget : public ShadowWindow
{
	Q_OBJECT

public:
	BeforeClosingWidget(QWidget *parent = 0);
	~BeforeClosingWidget();

private:

};

#endif // BEFORECLOSINGWIDGET_H
