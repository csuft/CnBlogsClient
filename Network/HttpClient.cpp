#include "HttpClient.h"


HttpClient::HttpClient(void): m_header(NULL)
{
	curl_global_init(CURL_GLOBAL_ALL);
	m_curl = curl_easy_init();
	// generate a HTTP header for web request.
	m_header = curl_slist_append(m_header,"User-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Win64; x64; Trident/5.0)"); 
	m_header = curl_slist_append(m_header,"Accept: text/html, application/xhtml+xml, */*");
    m_header = curl_slist_append(m_header,"Accept-Language:zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
    m_header = curl_slist_append(m_header,"Accept-Encoding:deflate");
    m_header = curl_slist_append(m_header,"Connection:keep-alive");
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
	if (m_curl == NULL || url == NULL || host == NULL || refer == NULL)
	{
		return false;
	}
	m_header = curl_slist_append(m_header, host);
	m_header = curl_slist_append(m_header, refer);

	curl_easy_setopt(m_curl, CURLOPT_COOKIEJAR, "cookie.dat");        // 把服务器发过来的cookie保存到cookie.txt
	curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, m_header);
	curl_easy_setopt(m_curl, CURLOPT_URL, url);  
	curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, params);  

	// whether to use POST or NOT;
	curl_easy_setopt(m_curl, CURLOPT_POST, usePost);	  
	curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1);  
	curl_easy_setopt(m_curl, CURLOPT_COOKIEFILE, "cookie.dat");
	curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, write_callback);  
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
        if (isalnum((unsigned char)str[i]) || 
            (str[i] == '-') ||
            (str[i] == '_') || 
            (str[i] == '.') || 
            (str[i] == '~') ||
			(str[i] == '&'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += "+";
        else
        {
            strTemp += '%';
            strTemp += ToHex((unsigned char)url[i] >> 4);
            strTemp += ToHex((unsigned char)url[i] % 16);
        }
    }
    return strTemp;
}

unsigned char HttpClient::toHex();
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
	const char* host = "Host: passport.cnblogs.com";

	if (downloadPage(0))
	{
		// build a parameters string for login request.
		map<string, string> params = getLoginParams();
		for (map<string, string>::const_iterator ci = params.cbegin(); ci != params.cend(); ++ci)
		{
			singleParam = ci->first + "=" + ci->second + "&";
			allParam.append(singleParam);
		}
		allParam = urlEncode(allParam);  // encode special characters.
		allParam += "tbUserName=" + userName + "&tbPassword=" + password + "&btnLogin=%E7%99%BB++%E5%BD%95&txtReturnUrl=http%3A%2F%2Fwww.cnblogs.com%2F";
		
		initialConnection(0, allParam.c_str(), url, host, refer, file);
		curl_easy_perform(getCurlHandle());
		fclose(file);

		// start parse login result
		if (XmlParser::getLoginResult(LOGIN_TEMP))
		{
			m_flags = true;
		}
	}
	
	m_flags = false;
}
/* 
 * Download the source file of the login page.
 */
bool HttpLogin::downloadPage(int page)
{
	FILE* file = fopen(LOGIN_TEMP, "w");
	CURLcode res = CURLE_FAILED_INIT;
	const char* url = "http://passport.cnblogs.com/login.aspx?ReturnUrl=http%3a%2f%2fwww.cnblogs.com%2f";
	const char* refer = "Referer: http://www.cnblogs.com/";
	const char* host = "Host: passport.cnblogs.com";

	initialConnection(0, NULL, url, host, refer, file);
	if (curl_easy_perform(getCurlHandle()) == CURLE_OK)
	{
		fclose(file);
		return true;
	}
	fclose(file);
	return false;
}

map<string, string> HttpLogin::getParams()
{
	return XmlParser::getLoginParams(LOGIN_TEMP);
}

HttpLogin::~HttpLogin()
{

}