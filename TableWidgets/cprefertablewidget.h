#ifndef CPREFERTABLEWIDGET_H
#define CPREFERTABLEWIDGET_H

#include <QTableView>
#include <QHeaderView>

#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
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
	CustomItemModel* m_model;

};

#endif // CPREFERTABLEWIDGET_H
