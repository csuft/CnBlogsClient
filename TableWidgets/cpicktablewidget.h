#ifndef CPICKTABLEWIDGET_H
#define CPICKTABLEWIDGET_H

#include <QTableView>
#include <QHeaderView>

#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
/*
 * CPickTableWidget存储精选博文
 */
class CPickTableWidget : public QTableView
{
	Q_OBJECT

public:
	CPickTableWidget(QWidget *parent);
	~CPickTableWidget();

private:
	CustomItemModel* m_model;
};

#endif // CPICKTABLEWIDGET_H
