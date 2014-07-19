#ifndef CNEWSTABLEWIDGET_H
#define CNEWSTABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
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
	
};

#endif // CNEWSTABLEWIDGET_H
