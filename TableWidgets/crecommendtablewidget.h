#ifndef CRECOMMENDTABLEWIDGET_H
#define CRECOMMENDTABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
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
	
};

#endif // CRECOMMENDTABLEWIDGET_H
