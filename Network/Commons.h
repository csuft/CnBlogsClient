#ifndef COMMONS_H
#define COMMONS_H

#include <string>
using std::string;
using std::wstring;

/*
 * These files are used to store temp data downloaded from the web server.
 * And we use these files to parse table items.
 */
#define HOME_TEMP "home.tmp"
#define LOGIN_TEMP "login.tmp"
#define PICKS_TEMP "picks.tmp"
#define CANDIDATES_TEMP "candidates.tmp"
#define VOTES_TEMP "votes.tmp"
#define NEWS_TEMP "news.tmp"
#define COMMENTS_TEMP "comments.tmp"
#define MYBLOGS_TEMP "myblogs.tmp"

typedef struct _article
{
	// 博主名字
	// 博文标题
	// 博文链接
	// 博文摘要
	// 阅读数
	// 推荐数
	// 评论数
	// 发表时间
	string postAttr[8];		
}Article;

#endif