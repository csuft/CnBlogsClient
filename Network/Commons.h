#ifndef COMMONS_H
#define COMMONS_H

#include <string>
using std::string;
using std::wstring;

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