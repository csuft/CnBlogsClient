#ifndef CNEWSTABLEWIDGET_H
#define CNEWSTABLEWIDGET_H

#include <QTableView>
#include <QHeaderView>

#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
/*
 * CNewsTableWidget 存储新闻列表
 */
class CNewsTableWidget : public QTableView
{
	Q_OBJECT

public:
	CNewsTableWidget(QWidget *parent);
	~CNewsTableWidget();

private:
	CustomItemModel* m_model;
};

#endif // CNEWSTABLEWIDGET_H
