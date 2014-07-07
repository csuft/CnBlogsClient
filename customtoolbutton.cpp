#include "customtoolbutton.h"

CustomToolButton::CustomToolButton(const QString& path, QWidget *parent)
	: QToolButton(parent), m_filePath(path)
{
	// Get the widget's palette, we do have to change the color of the tool button.
	QPalette text_palette = palette();
	text_palette.setColor(QPalette::ButtonText, QColor(202, 221, 254));
	setPalette(text_palette);
	// set the style of QToolButton.
	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	// set the font style of tool buttons
	// since the return value has the type of const, we have to remove the
	// constness if we want to modify.
	QFont text_font = const_cast<QFont&>(font());
	text_font.setBold(true);
	setFont(text_font);
	setCursor(Qt::PointingHandCursor);
	// set the fixed size for tool buttons.
	QPixmap background(m_filePath);
	setIcon(background);
	setIconSize(background.size());
	setFixedSize(100, 60);
	setAutoRaise(true);
	m_mousePressed = false;

}

void CustomToolButton::setButtonPressed(bool isPressed)
{
	m_mousePressed = isPressed;
	update();
}

void CustomToolButton::paintEvent(QPaintEvent *event)
{
	if (m_mousePressed)
	{
		setStyleSheet("border: 1px solid rgb(123, 129, 188); color: blue;");
	}
	else
	{
		setStyleSheet("border: none; color: rgb(202, 221, 254);");
	}

	QToolButton::paintEvent(event);
}

void CustomToolButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit clicked();
	}
}