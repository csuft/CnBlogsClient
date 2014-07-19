#ifndef CPICKTABLEWIDGET_H
#define CPICKTABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
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
	
};

#endif // CPICKTABLEWIDGET_H
