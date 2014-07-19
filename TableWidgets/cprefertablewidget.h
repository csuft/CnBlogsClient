#ifndef CPREFERTABLEWIDGET_H
#define CPREFERTABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
/*
 * CPreferTableWidget 存储我赞过的博文
 */
class CPreferTableWidget : public QTableView
{
	Q_OBJECT

public:
	CPreferTableWidget(QWidget *parent);
	~CPreferTableWidget();

private:
	
};

#endif // CPREFERTABLEWIDGET_H
