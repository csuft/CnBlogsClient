#ifndef CCANDIDATETABLEWIDGET_H
#define CCANDIDATETABLEWIDGET_H

#include <QTableWidget>
/*
 * CCandidateTableWidget存储候选博文
 */
class CCandidateTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	CCandidateTableWidget(QWidget *parent = NULL);
	~CCandidateTableWidget();

private:
	
};

#endif // CCANDIDATETABLEWIDGET_H
