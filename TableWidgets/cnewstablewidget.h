#ifndef CNEWSTABLEWIDGET_H
#define CNEWSTABLEWIDGET_H

#include <QTableWidget>
/*
 * CNewsTableWidget 存储新闻列表
 */
class CNewsTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CNewsTableWidget(QWidget *parent);
	~CNewsTableWidget();

private:
	
};

#endif // CNEWSTABLEWIDGET_H
