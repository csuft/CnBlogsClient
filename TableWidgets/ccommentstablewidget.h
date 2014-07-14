#ifndef CCOMMENTSTABLEWIDGET_H
#define CCOMMENTSTABLEWIDGET_H

#include <QTableWidget>
/*
 * CCommentsTableWidget 存储我评论我的博文
 */
class CCommentsTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CCommentsTableWidget(QWidget *parent);
	~CCommentsTableWidget();

private:
	
};

#endif // CCOMMENTSTABLEWIDGET_H
