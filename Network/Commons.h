#ifndef COMMONS_H
#define COMMONS_H

#include <string>
using std::string;
using std::wstring;

typedef struct _article
{
	wstring m_author;
	wstring m_title;
	wstring m_article_url;
	string  reads;			// 阅读数
	string	votes;			// 推荐数
	string	comments;		// 评论数
}Article;

#endif