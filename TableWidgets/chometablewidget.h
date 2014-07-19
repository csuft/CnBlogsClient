#ifndef CHOMETABLEWIDGET_H
#define CHOMETABLEWIDGET_H

#include <QTableView>
#include <QVector>
#include <QHeaderView>

#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/nofocusdelegate.h"
#include "BaseCtrl/loadingwidget.h"

/*
 * CHomeTableWidget 存储首页博文
 */
class CHomeTableWidget : public QTableView
{
	Q_OBJECT

public:
	CHomeTableWidget(QWidget *parent);
	~CHomeTableWidget();

private slots:
	void onUpdateList();

private:
	LoadingWidget* m_loadingWidget;
	bool flag;   // 是否需要加载内容
	CustomItemModel* m_model;
};

#endif // CHOMETABLEWIDGET_H
