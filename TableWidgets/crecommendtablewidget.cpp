#include "crecommendtablewidget.h"

CRecommendTableWidget::CRecommendTableWidget(QWidget *parent)
	: QTableView(parent)
{
	QVector<int> alignCenter;
	alignCenter << 0 << 1 << 2 << 3 << 4 << 5;
	m_model = new CustomItemModel(alignCenter, QVector<int>(), 0, 6, this);

	// set table header
	m_model->setHeaderData(0, Qt::Horizontal, QStringLiteral("排名"));
	m_model->setHeaderData(1, Qt::Horizontal, QStringLiteral("博主昵称"));
	m_model->setHeaderData(2, Qt::Horizontal, QStringLiteral("链接地址"));
	m_model->setHeaderData(3, Qt::Horizontal, QStringLiteral("园龄"));
	m_model->setHeaderData(4, Qt::Horizontal, QStringLiteral("粉丝数"));
	m_model->setHeaderData(5, Qt::Horizontal, QStringLiteral("他的关注"));
	// set table model
	setWordWrap(false);
	setMouseTracking(true);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setShowGrid(false);
	horizontalHeader()->setStretchLastSection(true);
	horizontalHeader()->setHighlightSections(false);
	setItemDelegate(new NoFocusDelegate());
	verticalHeader()->hide();
	setFrameShape(QFrame::NoFrame);
	setAlternatingRowColors(true);
	setModel(m_model);
}

CRecommendTableWidget::~CRecommendTableWidget()
{

}
