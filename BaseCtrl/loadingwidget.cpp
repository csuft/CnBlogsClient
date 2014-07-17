#include "loadingwidget.h"

LoadingWidget::LoadingWidget(QWidget *parent)
	: QWidget(parent)
{
	move(357, 120);
	m_vlayout = new QVBoxLayout(this);
	m_loading = new QLabel(this);
	m_desc = new QLabel(QStringLiteral("Loading data...Please wait!"), this);
	m_desc->setObjectName("loading");
	QMovie* loading_gif = new QMovie(this);
	loading_gif->setFileName(":/syspic/loading");
	m_loading->setMovie(loading_gif);
	loading_gif->start();

	m_vlayout->addWidget(m_loading, 0, Qt::AlignCenter);
	m_vlayout->addWidget(m_desc);

	setLayout(m_vlayout);
}

LoadingWidget::~LoadingWidget()
{

}
