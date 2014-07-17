#ifndef CHOMETABLEWIDGET_H
#define CHOMETABLEWIDGET_H

#include <QTableWidget>
#include "BaseCtrl/loadingwidget.h"

/*
 * CHomeTableWidget 存储首页博文
 */
class CHomeTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CHomeTableWidget(QWidget *parent);
	~CHomeTableWidget();

private:
	LoadingWidget* m_loadingWidget;
};

#endif // CHOMETABLEWIDGET_H
