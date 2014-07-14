#include "cstackedwidget.h"
#include <QMessageBox>

CStackedWidget::CStackedWidget(QWidget *parent)
	: QStackedWidget(parent)
{
	setFrameShape(QFrame::NoFrame);

	m_home = new CHomeTableWidget(this);				// 首页内容
	m_picks = new CPickTableWidget(this);				// 精选博文
	m_prefers = new CPreferTableWidget(this);			// 我赞过的博文
	m_news = new CNewsTableWidget(this);				// IT资讯
	m_myblogs = new CMyblogTableWidget(this);			// 我的博客
	m_candidates = new CCandidateTableWidget(this);		// 候选博文
	m_comments = new CCommentsTableWidget(this);		// 我评论过的博文
	m_recommends = new CRecommendTableWidget(this);		// 推荐博客前100强

	addWidget(m_home);
	addWidget(m_picks);
	addWidget(m_candidates);
	addWidget(m_news);
	addWidget(m_myblogs);
	addWidget(m_recommends);
	addWidget(m_comments);
	addWidget(m_prefers);

	// 将首页内容设置为第一屏
	setCurrentWidget(m_home);

}

CStackedWidget::~CStackedWidget()
{

}

void CStackedWidget::onWidgetsChoosed(int index)
{
	setCurrentIndex(index);
}