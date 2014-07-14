#ifndef CMYBLOGTABLEWIDGET_H
#define CMYBLOGTABLEWIDGET_H

#include <QTableWidget>
/*
 * CMyblogTableWidget 存储我的所有的博文
 */
class CMyblogTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CMyblogTableWidget(QWidget *parent);
	~CMyblogTableWidget();

private:
	
};

#endif // CMYBLOGTABLEWIDGET_H
