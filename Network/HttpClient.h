#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QThread>
#include <vector>
#include <map>
using std::vector;
using std::map;
using std::wstring;
using std::string;

#include "XmlParser.h"
#include "Commons.h"

class HttpClient : QThread
{
	Q_OBJECT

public:
	HttpClient();
	~HttpClient(void);

	void initialConnection();
	bool loginServer();
	wstring downloadPage();
	vector<Article> parseHomepage();
	vector<Article> parsePickings();
	vector<Article> parseCandidates();
	vector<Article> parseNews();
	vector<Article> parseMyposts();
	vector<map<wstring, wstring> > parseRecommends();
	vector<Article> parseMycomments();
	vector<Article> parseMyvotes();
	
private:
	wstring m_page;

};


#endif


