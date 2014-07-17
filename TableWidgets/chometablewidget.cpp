#include "chometablewidget.h"

CHomeTableWidget::CHomeTableWidget(QWidget *parent)
	: QTableWidget(parent)
{
	m_loadingWidget = new LoadingWidget(this);
	
}

CHomeTableWidget::~CHomeTableWidget()
{

}
