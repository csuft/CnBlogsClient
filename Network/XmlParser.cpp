#include "XmlParser.h"


XmlParser::XmlParser(void)
{
	// nothing to do
}


XmlParser::~XmlParser(void)
{
	// nothing to do
}
/*
 * 	1. __EVENTTARGET
 *	2. __EVENTARGUMENT
 *	3. __VIEWSTATE
 *	4. __EVENTVALIDATION
 *  模拟登陆时需要上述四个字段构造URL，因此在这里解析出来并返回
 */
map<string, string> XmlParser::getLoginParams(const char* fileName)
{
	map<string, string> params;
	
	// 从DOM树中获取两个迭代器，以迭代方式获取DOM元素
	tree<HTML::Node> dom = createDom(fileName);
	tree<HTML::Node>::iterator itStart = dom.begin();
	tree<HTML::Node>::iterator itEnd = dom.end();

	int count = 0;
	for (; itStart != itEnd; ++itStart)
	{
		// 检索到input元素，则解析Input元素的属性，获得name和value属性
		if (!itStart->tagName().compare("input"))
		{
			itStart->parseAttributes();
			params[itStart->attribute("name").second] = itStart->attribute("value").second;
			// 只需要解析完上述4对就满足要求了
			if (++count == 4)
			{
				break;
			}
		}
	}

	return params;
}
/*
 * 复用打开文件创建DOM的代码
 */
tree<HTML::Node> XmlParser::createDom(const char* fileName)
{
	HTML::ParserDom parser;
	fstream readFrom;
	readFrom.open(fileName, ios::in);
	istreambuf_iterator<char> fileBegin(readFrom), fileEnd;
	string html(fileBegin, fileEnd);
	readFrom.close(); 
	
	return parser.parseTree(html);
}
/*
 * 登陆请求发送给服务器之后，解析服务器的应答数据，确定是否登陆成功
 */
string XmlParser::getLoginResult(const char* fileName)
{
	string tempVal;
	tree<HTML::Node> dom = createDom(fileName);
	tree<HTML::Node>::iterator start = dom.begin();
	tree<HTML::Node>::iterator end = dom.end();

	for (; start != end; ++start)
	{
		// 检查返回页面中的span元素，分几种情况：
		// 1. 不存在span元素，则说明登录成功
		// 2. 存在span元素，说明登录失败，返回错误提示
		if (start->isTag() && !start->tagName().compare("span"))
		{
			start->parseAttributes();
			if (!start->attribute("id").second.compare("Message"))
			{
				// 提取该标签的html内容
				tempVal = (++start)->text();
			}
		}
	}

	return tempVal;
}
/*
 * 本函数为一个转发点，将具体的解析任务委托给对应的函数
 */
void XmlParser::parseArticles(vector<Article>& items, const char* fileName)
{
	tree<HTML::Node> dom = createDom(fileName);
	parseContents(items, dom);
}

/*
 * 该函数出于代码复用独立出来，解析每篇博文的八个字段：
 * 1. 
 */
void XmlParser::parseContents(vector<Article>& items, tree<HTML::Node>& dom)
{
	Article article;
	int count, index;
	bool flag;  
	string trimmedStr;

	tree<HTML::Node>::iterator start = dom.begin();
	tree<HTML::Node>::iterator end = dom.end();

	for (; start != end; ++start)
	{
		if (!start->tagName().compare("div"))
		{
			start->parseAttributes();
			if (!start->attribute("class").second.compare("post_item"))
			{
				// count的意义在于，我们只需要解析一篇博文的八个字段，又没有找到其他更好的跳出循环的方式
				// 于是用count做计数之用。而flag是为了只提取一个url，即博文URL，其他的URL不需要。
				count = 0;
				flag = false;
				// 使用string数组来存储八个字段，inde用来记录索引
				index = 0;
				for (; start != end; ++start)
				{
					if (!start->tagName().compare("a") && !flag)
					{
						start->parseAttributes();
						article.postAttr[index++] =  start->attribute("href").second;
						flag = true;
					}
					if (!start->isTag())
					{
						// 原始文件中存在大量的非打印字符，如' ', '\t', '\n', '\r', '\v'，在这里全部剔除
						trimmedStr = start->text();
						trimmedStr.erase(0,trimmedStr.find_first_not_of(" \t\v\r\n"));
						trimmedStr.erase(trimmedStr.find_last_not_of(" \t\v\r\n") + 1);
						if (!trimmedStr.empty())
						{
							article.postAttr[index++] = trimmedStr;
							++count;
						}
					}
					// 这里确实是7.尽管提取了八个字段，但是有两个字段是同时提取出来的 
					if (count == 7)
					{
						items.push_back(article);
						break;
					}
				}
			}
		}
	}
}