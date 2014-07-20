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
	HttpClient();
	~HttpClient(void);
	CURL* getCurlHandle() const { return m_curl; }
	struct curl_slist* getCurlHeader() const { return m_header; }
	string urlEncode(const string& url);
	unsigned char toHex();
protected:
	virtual void run();		// thread function, the start point of a thread.
	virtual bool initialConnection(int usePost, const char* params, const char* url, const char* host, const char* refer);
	virtual void downloadPage(int page = 0) = 0;
	virtual int getPages() const { return m_pages; }
	virtual void setPages(int page) { m_pages = page; } 
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
	bool downloadPage(int page = 0);
	map<string, string> getLoginParams();

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
	HttpHomePage();
	~HttpHomePage();
	const vector<Article>& getVector() const { return m_items;}

protected:
	void run();
	void parseHomepage();
private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with candidate posts.
 */
class HttpCandidates : HttpClient
{
public:
	HttpCandidates();
	~HttpCandidates();
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseCandidates();

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with posts which I commented.
 */
class HttpComments : HttpClient
{
public:
	HttpComments();
	~HttpComments();
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseMycomments();

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with my own posts.
 */
class HttpMyposts : HttpClient
{
public:
	HttpMyposts();
	~HttpMyposts();
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseMyposts();

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with IT news.
 */
class HttpNews : HttpClient
{
public:
	HttpNews();
	~HttpNews();
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseNews();

private:
	vector<Article> m_items;
};

/*
 * This class is used to deal with posts which are the best.
 */
class HttpPicks : HttpClient
{
public:
	HttpPicks();
	~HttpPicks();
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parsePickings();

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
	~HttpRecommends();
	const vector<map<wstring, wstring> >& getVector() const { return m_items; }

protected:
	void run();
	void parseRecommends();

private:
	vector<map<wstring, wstring> > m_items;
};

/*
 * This class is used to deal with posts which I voted.
 */
class HttpVotes : HttpClient
{
public:
	HttpVotes();
	~HttpVotes();
	const vector<Article>& getVector() const { return m_items; }

protected:
	void run();
	void parseMyvotes();

private:
	vector<Article> m_items;
};


#endif


