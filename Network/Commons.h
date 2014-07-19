#ifndef COMMONS_H
#define COMMONS_H

#include <string>
using std::string;
using std::wstring;

typedef struct _article
{
	wstring m_author;		// 博主名字
	wstring m_aurl;			// 博主链接
	wstring m_title;		// 博文标题
	wstring m_turl;			// 博文链接
	string  reads;			// 阅读数
	string	votes;			// 推荐数
	string	comments;		// 评论数
}Article;

#endif