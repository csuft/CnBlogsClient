#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <vector>
#include <map>
#include <string>

#include "Commons.h"

using std::vector;
using std::map;
using std::string;

class XmlParser
{
public:
	XmlParser(void);
	~XmlParser(void);

	enum ParseType{
		HOMEPAGE,
		CANDIDATES,
		PICKINGS,
		MYPOSTS,
		MYCOMMENTS,
		MYVOTES,
		NEWS
	};

	static map<string, string> getLoginParams(const char* fileName);
	static bool getLoginResult(const char* fileName);

	static void parseArticles(vector<Article>& items, const char* fileName, ParseType type);

private:

};

#endif


