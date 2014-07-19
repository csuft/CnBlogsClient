#ifndef CMYBLOGTABLEWIDGET_H
#define CMYBLOGTABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
/*
 * CMyblogTableWidget 存储我的所有的博文
 */
class CMyblogTableWidget : public QTableView
{
	Q_OBJECT

public:
	CMyblogTableWidget(QWidget *parent);
	~CMyblogTableWidget();

private:
	
};

#endif // CMYBLOGTABLEWIDGET_H
