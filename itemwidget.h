#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
/*
 * This class represents a custom item in list widget by which we show
 * all content items.
 */
class ItemWidget : public QWidget
{
	Q_OBJECT

public:
	ItemWidget(QWidget *parent);
	~ItemWidget();

private:
	
};

#endif // ITEMWIDGET_H
