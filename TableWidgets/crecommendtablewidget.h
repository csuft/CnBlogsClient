#ifndef CRECOMMENDTABLEWIDGET_H
#define CRECOMMENDTABLEWIDGET_H

#include <QTableView>
#include <QHeaderView>

#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
/*
 * CRecommendTableWidget 存储推荐博客，前100名
 */
class CRecommendTableWidget : public QTableView
{
	Q_OBJECT

public:
	CRecommendTableWidget(QWidget *parent);
	~CRecommendTableWidget();

private:
	CustomItemModel* m_model;
};

#endif // CRECOMMENDTABLEWIDGET_H
