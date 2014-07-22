#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QThread>
#include <vector>
#include <map>
using std::vector;
using std::map;
using std::wstring;
using std::string;

#include "XmlParser.h"
#include "Commons.h"
#include "3rdParty/include/curl.h"

#pragma comment(lib, "libcurl.lib")

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

/*
 * The base class which implements the common functionalities, such as
 * initialize the traffic environment, make connections with web server.
 */
class HttpClient : QThread
{
	Q_OBJECT

public:
	typedef size_t (*WriteFunc)(char *data, int size, int nmemb, void* stream);

	HttpClient();
	~HttpClient(void);
	CURL* getCurlHandle() const { return m_curl; }
	struct curl_slist* getCurlHeader() const { return m_header; }
	int getPages() const { return m_pages; }
	void setPages(int page) { m_pages = page; } 

protected:
	virtual void run(){}		// thread function, the start point of a thread.
	virtual bool initialConnection(int usePost, const char* params, const char* url, const char* host, const char* refer, FILE* file);
	virtual bool downloadPage(int page = 1) = 0;
	string urlEncode(const string& url);
	unsigned char toHex(int x);
	virtual size_t write_callback(char* data, int size, int nmemb, void* stream); 

private:
	int m_pages;
	CURL* m_curl;
	struct curl_slist* m_header;
};

/*
 * This class represents the login process
 */
class HttpLogin : HttpClient
{
public:
	HttpLogin(string userName, string password) : m_strName(userName), m_strPasswd(password) {}
	~HttpLogin();
	bool getState() const { return m_flags; }

protected:
	void run();
	void loginServer();
	bool downloadPage(int page = 1);
	map<string, string> getParams();

private:
	bool m_flags;
	string m_strName;
	string m_strPasswd;
};

/*
 * This class is used to deal with home page.
 */
class HttpHomePage : HttpClient
{
public:
	HttpHomePage(int page);
	~HttpHomePage(){}
	const vector<Article>& getVector() const { return m_items;}

protected:
	void run();
	void parseHomepage();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with candidate posts.
 */
class HttpCandidates : HttpClient
{
public:
	HttpCandidates(int page);
	~HttpCandidates(){}
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseCandidates();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with posts which I commented.
 */
class HttpComments : HttpClient
{
public:
	HttpComments(int page);
	~HttpComments(){}
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseMycomments();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with my own posts.
 */
class HttpMyposts : HttpClient
{
public:
	HttpMyposts(int page);
	~HttpMyposts(){}
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseMyposts();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with IT news.
 */
class HttpNews : HttpClient
{
public:
	HttpNews(int page);
	~HttpNews(){}
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseNews();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with posts which are the best.
 */
class HttpPicks : HttpClient
{
public:
	HttpPicks(int page);
	~HttpPicks(){}
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parsePickings();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;	
};

/*
 * This class is used to deal with recommended bloggers.
 */
class HttpRecommends : HttpClient
{
public:
	HttpRecommends();
	~HttpRecommends(){}
	const map<wstring, wstring>& getVector() const { return m_items; }

protected:
	void run();
	void parseRecommends();
	bool downloadPage(int page = 1);

private:
	map<wstring, wstring> m_items;
};

/*
 * This class is used to deal with posts which I voted.
 */
class HttpVotes : HttpClient
{
public:
	HttpVotes(int page);
	~HttpVotes(){}
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseMyvotes();
	bool downloadPage(int page = 1);

private:
	vector<Article> m_items;
};


#endif


