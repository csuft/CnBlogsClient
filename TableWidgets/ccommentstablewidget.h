#ifndef CCOMMENTSTABLEWIDGET_H
#define CCOMMENTSTABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
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
	
};

#endif // CCOMMENTSTABLEWIDGET_H
