#ifndef CPREFERTABLEWIDGET_H
#define CPREFERTABLEWIDGET_H

#include <QTableWidget>
/*
 * CPreferTableWidget 存储我赞过的博文
 */
class CPreferTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CPreferTableWidget(QWidget *parent);
	~CPreferTableWidget();

private:
	
};

#endif // CPREFERTABLEWIDGET_H
