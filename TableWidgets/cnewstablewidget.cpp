#include "cnewstablewidget.h"

CNewsTableWidget::CNewsTableWidget(QWidget *parent)
	: QTableView(parent)
{
	QVector<int> alignCenter;
	alignCenter << 1 << 2 << 3 << 4 << 5;
	m_model = new CustomItemModel(alignCenter, QVector<int>(), 0, 7, this);

	// set headers
	m_model->setHeaderData(0, Qt::Horizontal, QPixmap(":/syspic/checkmark"), Qt::DecorationRole);
	m_model->setHeaderData(1, Qt::Horizontal, QStringLiteral("新闻标题"));
	m_model->setHeaderData(2, Qt::Horizontal, QStringLiteral("发布时间"));
	m_model->setHeaderData(3, Qt::Horizontal, QStringLiteral("发布人"));
	m_model->setHeaderData(4, Qt::Horizontal, QStringLiteral("浏览数"));
	m_model->setHeaderData(5, Qt::Horizontal, QStringLiteral("推荐数"));
	m_model->setHeaderData(6, Qt::Horizontal, QStringLiteral("评论数"));

	// table view properties
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

CNewsTableWidget::~CNewsTableWidget()
{

}
