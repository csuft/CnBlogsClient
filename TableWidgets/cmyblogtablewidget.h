#ifndef CMYBLOGTABLEWIDGET_H
#define CMYBLOGTABLEWIDGET_H

#include <QTableView>
#include <QHeaderView>

#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
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
	CustomItemModel* m_model;
};

#endif // CMYBLOGTABLEWIDGET_H
