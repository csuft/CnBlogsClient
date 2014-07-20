#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class XmlParser
{
public:
	XmlParser(void);
	~XmlParser(void);

	static map<string, string> getLoginParams(const char* fileName);
	static bool getLoginResult(const char* fileName);
};

#endif


