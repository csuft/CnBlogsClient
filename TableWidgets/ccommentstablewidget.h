#ifndef CCOMMENTSTABLEWIDGET_H
#define CCOMMENTSTABLEWIDGET_H

#include <QTableView>
#include <QHeaderView>

#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
/*
 * CCommentsTableWidget 存储我评论我的博文
 */
class CCommentsTableWidget : public QTableView
{
	Q_OBJECT

public:
	CCommentsTableWidget(QWidget *parent);
	~CCommentsTableWidget();

private:
	CustomItemModel* m_model;
};

#endif // CCOMMENTSTABLEWIDGET_H
