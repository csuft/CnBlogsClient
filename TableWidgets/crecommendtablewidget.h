#ifndef CRECOMMENDTABLEWIDGET_H
#define CRECOMMENDTABLEWIDGET_H

#include <QTableWidget>
/*
 * CRecommendTableWidget 存储推荐博客，前100名
 */
class CRecommendTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CRecommendTableWidget(QWidget *parent);
	~CRecommendTableWidget();

private:
	
};

#endif // CRECOMMENDTABLEWIDGET_H
