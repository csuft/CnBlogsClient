#include "HttpClient.h"

HttpClient::HttpClient(void): m_pages(1)
{
	curl_global_init(CURL_GLOBAL_ALL);
	m_curl = curl_easy_init();
}
/*
 * release libcurl resources
 */
HttpClient::~HttpClient(void)
{
	curl_easy_cleanup(m_curl);
	curl_slist_free_all(m_header);
	curl_global_cleanup();
}

/*
 * set up all parameters for HTTP header and curl library.
 */
bool HttpClient::initialConnection(int usePost, 
								   const char* params, 
								   const char* url, 
								   const char* host, 
								   const char* refer, 
								   FILE* file)
{
	if (m_curl == NULL || url == NULL || host == NULL || file == NULL)
	{
		return false;
	}
	m_header = NULL;
	// generate a HTTP header for web request.
	m_header = curl_slist_append(m_header,"User-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Win64; x64; Trident/5.0)"); 
	m_header = curl_slist_append(m_header, host);
	m_header = curl_slist_append(m_header,"Accept: text/html, application/xhtml+xml, */*");
    m_header = curl_slist_append(m_header,"Accept-Language:zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    m_header = curl_slist_append(m_header,"Accept-Encoding:deflate");
    m_header = curl_slist_append(m_header, refer);
	m_header = curl_slist_append(m_header,"Connection:keep-alive");
	
	curl_easy_setopt(m_curl, CURLOPT_COOKIEJAR, "cookie.dat");        // 把服务器发过来的cookie保存到cookie.txt
	curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, m_header);
	curl_easy_setopt(m_curl, CURLOPT_URL, url);  
	curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, params);  

	// whether to use POST or NOT;
	curl_easy_setopt(m_curl, CURLOPT_POST, usePost);	   
	curl_easy_setopt(m_curl, CURLOPT_COOKIEFILE, "cookie.dat");
	curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, &HttpClient::write_callback);  
	curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, file); 

	return true;
}

size_t HttpClient::write_callback(char *data, int size, int nmemb, void* stream)
{
	int written = fwrite(data, size, nmemb, (FILE *)stream);
	return written;
}
/*
 * Encoding URL to replace '/', blank space and other nonprintable characters.
 */
string HttpClient::urlEncode(const string& url)
{
	string strTemp = "";
    size_t length = url.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)url[i]) || 
            (url[i] == '-') ||
            (url[i] == '_') || 
            (url[i] == '.') || 
            (url[i] == '~') ||
			(url[i] == '&') ||
			(url[i] == '='))
            strTemp += url[i];
        else if (url[i] == ' ')
            strTemp += "+";
        else
        {
            strTemp += '%';
            strTemp += toHex((unsigned char)url[i] >> 4);
            strTemp += toHex((unsigned char)url[i] % 16);
        }
    }
    return strTemp;
}
//////////////////////////////////////////////////////////////////////////
unsigned char HttpClient::toHex(int x)
{
	 return  x > 9 ? x + 55 : x + 48; 
}

void HttpLogin::run()
{
	loginServer();
}

void HttpLogin::loginServer()
{
	FILE* file = fopen(LOGIN_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	string allParam, singleParam;
	const char* url = "http://passport.cnblogs.com/login.aspx?ReturnUrl=http%3a%2f%2fwww.cnblogs.com%2f";
	const char* refer = "Referer: http://passport.cnblogs.com/login.aspx?ReturnUrl=http%3A%2F%2Fwww.cnblogs.com%2F";
	const char* host = "Host:passport.cnblogs.com";

	if (downloadPage(0))
	{
		// build a parameters string for login request.
		map<string, string> params = getParams();
		for (map<string, string>::const_iterator ci = params.cbegin(); ci != params.cend(); ++ci)
		{
			singleParam = ci->first + "=" + ci->second + "&";
			allParam.append(singleParam);
		}
		allParam = urlEncode(allParam);  // translate special characters.
		allParam += "tbUserName=" + m_strName + "&tbPassword=" + m_strPasswd + "&btnLogin=%E7%99%BB++%E5%BD%95&txtReturnUrl=http%3A%2F%2Fwww.cnblogs.com%2F";
		initialConnection(1, allParam.c_str(), url, host, refer, file);
		res = curl_easy_perform(getCurlHandle());
		fclose(file);

		// start parse login result
		m_loginResult = XmlParser::getLoginResult(LOGIN_TEMP);
	}
}
/* 
 * Download the source file of the login page.
 */
bool HttpLogin::downloadPage(int page)
{
	FILE* file = fopen(LOGIN_TEMP, "w");
	const char* url = "http://passport.cnblogs.com/login.aspx?ReturnUrl=http%3a%2f%2fwww.cnblogs.com%2f";
	const char* refer = "Referer: http://www.cnblogs.com/";
	const char* host = "Host: passport.cnblogs.com";
	bool flags = false;

	initialConnection(0, NULL, url, host, refer, file);
	if (curl_easy_perform(getCurlHandle()) == CURLE_OK)
	{
		flags = true;
	}
	fclose(file);
	
	return flags;
}

map<string, string> HttpLogin::getParams()
{
	return XmlParser::getLoginParams(LOGIN_TEMP);
}

HttpLogin::~HttpLogin()
{

}
//////////////////////////////////////////////////////////////////////////
// home page.
HttpHomePage::HttpHomePage(int page)
{
	setPages(page);
}

void HttpHomePage::run()
{
	parseHomepage();
}

void HttpHomePage::parseHomepage()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, HOME_TEMP);
	}
}

bool HttpHomePage::downloadPage(int page /* = 1 */)
{
	FILE* file = fopen(HOME_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	int usePost = 0;
	char params[512] = {'\0'};
	char chRefer[256] = {'\0'};
	string url, host;
	string refer = "";

	host = "Host: www.cnblogs.com";
	// If what we want is the first page, we use GET method instead
	// and dont sent extra JSON data. URL and refer are little different.
	if (page == 1) 
	{
		url = "http://www.cnblogs.com/";
		usePost = 0;
	}
	else
	{
		// If we want the rest pages, then we have to use POST method to send JSON data to web server
		sprintf(chRefer, "Referer: http://www.cnblogs.com/#p%d", page);
		sprintf(params, "{'CategoryType':'SiteHome','ParentCategoryId':0,'CategoryId':808,'PageIndex':%d,'ItemListActionName':'PostList'}", page);
		url = "http://www.cnblogs.com/mvc/AggSite/PostList.aspx";
		refer = chRefer;
		usePost = 1; 
	}

	initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	fclose(file);

	return curl_easy_perform(getCurlHandle()) == CURLE_OK;

}
//////////////////////////////////////////////////////////////////////////
// candidate posts
HttpCandidates::HttpCandidates(int page)
{
	setPages(page);
}

void HttpCandidates::run()
{
	parseCandidates();
}

void HttpCandidates::parseCandidates()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, CANDIDATES_TEMP);
	}
}

bool HttpCandidates::downloadPage(int page /* = 1 */)
{
	// {"CategoryType":"HomeCandidate","ParentCategoryId":0,"CategoryId":108697,"PageIndex":2,"ItemListActionName":"PostList"}
	FILE* file = fopen(CANDIDATES_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	int usePost = 0;
	char params[512] = {'\0'};
	char chRefer[256] = {'\0'};
	string url, host;
	string refer = "";

	host = "Host: www.cnblogs.com";
	// If what we want is the first page, we use GET method instead
	// and dont sent extra JSON data. URL and refer are little different.
	if (page == 1) 
	{
		url = "http://www.cnblogs.com/candidate/";
		refer = "Referer: http://www.cnblogs.com/";
		usePost = 0;
	}
	else
	{
		// If we want the rest pages, we then use POST method to send JSON data to web server
		sprintf(chRefer, "Referer: http://www.cnblogs.com/candidate/#p%d", page);
		sprintf(params, "{'CategoryType':'HomeCandidate','ParentCategoryId':0,'CategoryId':108697,'PageIndex':%d,'ItemListActionName':'PostList'}", page);
		url = "http://www.cnblogs.com/mvc/AggSite/PostList.aspx";
		refer = chRefer;
		usePost = 1; 
	}

	initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	fclose(file);

	return curl_easy_perform(getCurlHandle()) == CURLE_OK;
}

//////////////////////////////////////////////////////////////////////////
// my comments
HttpComments::HttpComments(int page)
{
	setPages(page);
}

void HttpComments::run()
{
	parseMycomments();
}

void HttpComments::parseMycomments()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, COMMENTS_TEMP);
	}
}

bool HttpComments::downloadPage(int page /* = 0 */)
{
	// {"CategoryType":"MyCommented","ParentCategoryId":0,"CategoryId":0,"PageIndex":2,"ItemListActionName":"PostList"}
	FILE* file = fopen(COMMENTS_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	int usePost = 0;
	char params[512] = {'\0'};
	char chRefer[256] = {'\0'};
	string url, host;
	string refer = "";

	host = "Host: www.cnblogs.com";
	// If what we want is the first page, we use GET method instead
	// and dont sent extra JSON data. URL and refer are little different.
	if (page == 1) 
	{
		url = "http://www.cnblogs.com/aggsite/mycommented";
		refer = "Referer: http://www.cnblogs.com/";
		usePost = 0;
	}
	else
	{
		// If we want the rest pages, we then use POST method to send JSON data to web server
		sprintf(chRefer, "Referer: http://www.cnblogs.com/aggsite/mycommented#p%d", page);
		sprintf(params, "{'CategoryType':'MyCommented','ParentCategoryId':0,'CategoryId':0,'PageIndex':%d,'ItemListActionName':'PostList'}", page);
		url = "http://www.cnblogs.com/mvc/AggSite/PostList.aspx";
		refer = chRefer;
		usePost = 1; 
	}

	initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	fclose(file);

	return curl_easy_perform(getCurlHandle()) == CURLE_OK;
}

//////////////////////////////////////////////////////////////////////////
// my posts
// 由于博客园的页面风格运行自定制，定制过的博客DOM结构异构性太大，解析工作难以统一完成
HttpMyposts::HttpMyposts(int page)
{

}

void HttpMyposts::run()
{
	parseMyposts();
}

void HttpMyposts::parseMyposts()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, MYBLOGS_TEMP);
	} 
}

bool HttpMyposts::downloadPage(int page /* = 0 */)
{
	return false;
}

//////////////////////////////////////////////////////////////////////////
// news
HttpNews::HttpNews(int page)
{
	setPages(page);
}

void HttpNews::run()
{
	parseNews();
}

void HttpNews::parseNews()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, NEWS_TEMP);
	}
}

bool HttpNews::downloadPage(int page /* = 0 */)
{
	// {"CategoryType":"News","ParentCategoryId":0,"CategoryId":-1,"PageIndex":2,"ItemListActionName":"NewsList"}
	FILE* file = fopen(NEWS_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	int usePost = 0;
	char params[512] = {'\0'};
	char chRefer[256] = {'\0'};
	string url, host;
	string refer = "";

	host = "Host: www.cnblogs.com";
	// If what we want is the first page, we use GET method instead
	// and dont sent extra JSON data. URL and refer are little different.
	if (page == 1) 
	{
		url = "http://www.cnblogs.com/news/";
		refer = "Referer: http://www.cnblogs.com/";
		usePost = 0;
	}
	else
	{
		// If we want the rest pages, we then use POST method to send JSON data to web server
		sprintf(chRefer, "Referer: http://www.cnblogs.com/news/#p%d", page);
		sprintf(params, "{'CategoryType':'News','ParentCategoryId':0,'CategoryId':-1,'PageIndex':%d,'ItemListActionName':'NewsList'}", page);
		url = "http://www.cnblogs.com/mvc/AggSite/NewsList.aspx";
		refer = chRefer;
		usePost = 1; 
	}

	initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	fclose(file);

	return curl_easy_perform(getCurlHandle()) == CURLE_OK;
}

//////////////////////////////////////////////////////////////////////////
// picks
HttpPicks::HttpPicks(int page)
{
	setPages(page);
}

void HttpPicks::run()
{
	parsePickings();
}

void HttpPicks::parsePickings()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, PICKS_TEMP);
	}
}

bool HttpPicks::downloadPage(int page /* = 0 */)
{
	// {"CategoryType":"Picked","ParentCategoryId":0,"CategoryId":-2,"PageIndex":2,"ItemListActionName":"PostList"}
	FILE* file = fopen(PICKS_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	int usePost = 0;
	char params[512] = {'\0'};
	char chRefer[256] = {'\0'};
	string url, host;
	string refer = "";

	host = "Host: www.cnblogs.com";
	// If what we want is the first page, we use GET method instead
	// and dont sent extra JSON data. URL and refer are little different.
	if (page == 1) 
	{
		url = "http://www.cnblogs.com/pick/";
		refer = "Referer: http://www.cnblogs.com/";
		usePost = 0;
	}
	else
	{
		// If we want the rest pages, we then use POST method to send JSON data to web server
		sprintf(chRefer, "Referer: http://www.cnblogs.com/pick/#p%d", page);
		sprintf(params, "{'CategoryType':'Picked','ParentCategoryId':0,'CategoryId':-2,'PageIndex':%d,'ItemListActionName':'PostList'}", page);
		url = "http://www.cnblogs.com/mvc/AggSite/PostList.aspx";
		refer = chRefer;
		usePost = 1; 
	}

	initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	fclose(file);

	return curl_easy_perform(getCurlHandle()) == CURLE_OK;
}

//////////////////////////////////////////////////////////////////////////
// Recommend blogs
// 推荐博客的解析可以从任何一个页面的源码中进行解析
HttpRecommends::HttpRecommends(int page)
{
	setPages(page);
}

void HttpRecommends::run()
{
	parseRecommends();
}

void HttpRecommends::parseRecommends()
{
	//if (downloadPage(getPages()))
	//{
	//	XmlParser::parseArticles(m_items, PICKS_TEMP);
	//}
}

bool HttpRecommends::downloadPage(int page /* = 0 */)
{
	//FILE* file = fopen(VOTES_TEMP, "w");
	//CURLcode res = CURLE_FAILED_INIT;
	//int usePost = 0;
	//char params[512] = {'\0'};
	//char chRefer[256] = {'\0'};
	//string url, host;
	//string refer = "";

	//host = "Host: www.cnblogs.com";
	//// If what we want is the first page, we use GET method instead
	//// and dont sent extra JSON data. URL and refer are little different.
	//if (page == 1) 
	//{
	//	url = "http://www.cnblogs.com/aggsite/mydigged";
	//	refer = "Referer: http://www.cnblogs.com/";
	//	usePost = 0;
	//}
	//else
	//{
	//	// If we want the rest pages, we then use POST method to send JSON data to web server
	//	sprintf(chRefer, "Referer: http://www.cnblogs.com/aggsite/mydigged#p%d", page);
	//	sprintf(params, "{'CategoryType':'MyDigged','ParentCategoryId':0,'CategoryId':0,'PageIndex':%d,'ItemListActionName':'PostList'}", page);
	//	url = "http://www.cnblogs.com/mvc/AggSite/PostList.aspx";
	//	refer = chRefer;
	//	usePost = 1; 
	//}

	//initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	//fclose(file);

	//return curl_easy_perform(getCurlHandle()) == CURLE_OK;

	return false;
}

//////////////////////////////////////////////////////////////////////////
// votes
HttpVotes::HttpVotes(int page)
{
	setPages(page);
}

void HttpVotes::run()
{
	parseMyvotes();
}

void HttpVotes::parseMyvotes()
{
	if (downloadPage(getPages()))
	{
		XmlParser::parseArticles(m_items, VOTES_TEMP);
	}
}

bool HttpVotes::downloadPage(int page /* = 0 */)
{
	// {"CategoryType":"MyDigged","ParentCategoryId":0,"CategoryId":0,"PageIndex":2,"ItemListActionName":"PostList"}
	FILE* file = fopen(VOTES_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	int usePost = 0;
	char params[512] = {'\0'};
	char chRefer[256] = {'\0'};
	string url, host;
	string refer = "";

	host = "Host: www.cnblogs.com";
	// If what we want is the first page, we use GET method instead
	// and dont sent extra JSON data. URL and refer are little different.
	if (page == 1) 
	{
		url = "http://www.cnblogs.com/aggsite/mydigged";
		refer = "Referer: http://www.cnblogs.com/";
		usePost = 0;
	}
	else
	{
		// If we want the rest pages, we then use POST method to send JSON data to web server
		sprintf(chRefer, "Referer: http://www.cnblogs.com/aggsite/mydigged#p%d", page);
		sprintf(params, "{'CategoryType':'MyDigged','ParentCategoryId':0,'CategoryId':0,'PageIndex':%d,'ItemListActionName':'PostList'}", page);
		url = "http://www.cnblogs.com/mvc/AggSite/PostList.aspx";
		refer = chRefer;
		usePost = 1; 
	}

	initialConnection(usePost, params, url.c_str(), host.c_str(), refer.c_str(), file);
	fclose(file);

	return curl_easy_perform(getCurlHandle()) == CURLE_OK;
}