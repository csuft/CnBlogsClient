#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>

class LoadingWidget : public QWidget
{
	Q_OBJECT

public:
	LoadingWidget(QWidget *parent);
	~LoadingWidget();

private:
	QLabel* m_loading;
	QVBoxLayout* m_vlayout;
	QLabel* m_desc;
};

#endif // LOADINGWIDGET_H
