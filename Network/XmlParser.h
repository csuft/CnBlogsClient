#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <vector>
#include <map>
#include <string>
#include <fstream>

#include "Commons.h"
#include "ParserDom.h"
#pragma comment(lib, "htmlcxx.lib")

using namespace std;
using namespace htmlcxx;

class XmlParser
{
public:
	XmlParser(void);
	~XmlParser(void);

	static map<string, string> getLoginParams(const char* fileName);
	static bool getLoginResult(const char* fileName);

	static void parseArticles(vector<Article>& items, const char* fileName);
	static void parseRecommends(map<string, string> bloggers, const char* fileName);
private:
	static tree<HTML::Node> createDom(const char* file);
	static void parseContents(vector<Article>& items,tree<HTML::Node>& dom);
};

#endif


