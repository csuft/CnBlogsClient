#ifndef PROMPTWINDOW_H
#define PROMPTWINDOW_H

#include <QWidget>
/*
 * When new essays published, we sent notifications to users
 * by prompt a window on the left bottom edge.
 */
class PromptWindow : public QWidget
{
	Q_OBJECT

public:
	PromptWindow(QWidget *parent);
	~PromptWindow();

private:
	
};

#endif // PROMPTWINDOW_H
