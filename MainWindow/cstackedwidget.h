#ifndef CSTACKEDWIDGET_H
#define CSTACKEDWIDGET_H

#include <QStackedWidget>

#include "TableWidgets/ccandidatetablewidget.h"
#include "TableWidgets/ccommentstablewidget.h"
#include "TableWidgets/chometablewidget.h"
#include "TableWidgets/cmyblogtablewidget.h"
#include "TableWidgets/cnewstablewidget.h"
#include "TableWidgets/cpicktablewidget.h"
#include "TableWidgets/cprefertablewidget.h"
#include "TableWidgets/crecommendtablewidget.h"

/*
 * 主窗口中的堆栈式组件
 */
class CStackedWidget : public QStackedWidget
{
	Q_OBJECT

public:
	CStackedWidget(QWidget *parent);
	~CStackedWidget();

private slots:
	void onWidgetsChoosed(int index);

private:
	// widgets for stacked layout
	CHomeTableWidget* m_home;
	CCandidateTableWidget* m_candidates;
	CPickTableWidget* m_picks;
	CPreferTableWidget* m_prefers;
	CRecommendTableWidget* m_recommends;
	CCommentsTableWidget* m_comments;
	CNewsTableWidget* m_news;
	CMyblogTableWidget* m_myblogs;
};

#endif // CSTACKEDWIDGET_H
