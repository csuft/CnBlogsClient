#ifndef CCANDIDATETABLEWIDGET_H
#define CCANDIDATETABLEWIDGET_H

#include <QTableView>

#include "BaseCtrl/customitemmodel.h"
#include "BaseCtrl/loadingwidget.h"
/*
 * CCandidateTableWidget存储候选博文
 */
class CCandidateTableWidget : public QTableView
{
	Q_OBJECT

public:
	CCandidateTableWidget(QWidget *parent = NULL);
	~CCandidateTableWidget();

private:
	LoadingWidget* m_loadingWidget;
	
};

#endif // CCANDIDATETABLEWIDGET_H
