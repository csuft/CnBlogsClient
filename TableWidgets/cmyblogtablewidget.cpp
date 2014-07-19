#include "cmyblogtablewidget.h"

CMyblogTableWidget::CMyblogTableWidget(QWidget *parent)
	: QTableView(parent)
{
	QVector<int> alignCenter;
	alignCenter << 0 << 2 << 3 << 4 << 5;
	m_model = new CustomItemModel(alignCenter, QVector<int>(), 0, 6, this);

	// set table header
	m_model->setHeaderData(0, Qt::Horizontal, QStringLiteral("博文标题"));
	m_model->setHeaderData(1, Qt::Horizontal, QStringLiteral("发表时间"));
	m_model->setHeaderData(2, Qt::Horizontal, QStringLiteral("浏览数"));
	m_model->setHeaderData(3, Qt::Horizontal, QStringLiteral("推荐数"));
	m_model->setHeaderData(4, Qt::Horizontal, QStringLiteral("评论数"));
	m_model->setHeaderData(5, Qt::Horizontal, QStringLiteral("博文链接"));

	// set table model
	setWordWrap(false);
	setMouseTracking(true);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setShowGrid(false);
	horizontalHeader()->setHighlightSections(false);
	setItemDelegate(new NoFocusDelegate());
	verticalHeader()->hide();
	setFrameShape(QFrame::NoFrame);
	setAlternatingRowColors(true);
	setModel(m_model);
}

CMyblogTableWidget::~CMyblogTableWidget()
{

}
