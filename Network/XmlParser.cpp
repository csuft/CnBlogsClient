#include "XmlParser.h"


XmlParser::XmlParser(void)
{

}


XmlParser::~XmlParser(void)
{

}

map<string, string> XmlParser::getLoginParams(const char* fileName)
{
	// __EVENTTARGET
	// __EVENTARGUMENT
	// __VIEWSTATE
	// __EVENTVALIDATION
	char chValue[512];
	map<string, string> params;
	QFile file(fileName);
	file.open(QFile::ReadOnly);
	uchar *memory = file.map(0, file.size());
	if (memory)
	{
		// __EVENTTARGET
		params["__EVENTTARGET"] = string("");
		// __EVENTARGUMENT
		params["__EVENTARGUMENT"] = string("");
		// __VIEWSTATE
		char* before = strstr((char*)memory, "__VIEWSTATE");
		before = strchr(before, '=');
		before += 2;
		char* after = strchr(before, '\"');
		size_t length = after - before;
		strncpy(chValue, before, length);
		params["__VIEWSTATE"] = chValue;
		// __EVENTVALIDATION
		before = strstr(before, "__EVENTVALIDATION");
		before = strchr(before, '=');
		before += 2;
		after = strchr(before, '\"');
		length = after - before;
		strncpy(chValue, before, length);
		params["__EVENTVALIDATION"] = chValue;

		file.unmap(memory);
	}

	return params;
}

bool XmlParser::getLoginResult(const char* fileName)
{

	return false;
}

void XmlParser::parseArticles(vector<Article>& items, const char* fileName, ParseType type)
{


}

void XmlParser::parseHomepage(vector<Article>& items, const char* fileName)
{


}

void XmlParser::parsePickings(vector<Article>& items, const char* fileName)
{

}

void XmlParser::parseCandidates(vector<Article>& items, const char* fileName)
{

}

void XmlParser::parseNews(vector<Article>& items, const char* fileName)
{

}

void XmlParser::parseMyposts(vector<Article>& items, const char* fileName)
{

}

void XmlParser::parseMyComments(vector<Article>& items, const char* fileName)
{

}

void XmlParser::parseMyVotes(vector<Article>& items, const char* fileName)
{

}

