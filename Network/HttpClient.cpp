#include "HttpClient.h"


HttpClient::HttpClient(void)
{
}


HttpClient::~HttpClient(void)
{
}

void HttpClient::initialConnection()
{


}
bool HttpClient::loginServer()
{
	return false;
}
wstring HttpClient::downloadPage()
{
	return wstring();
}
vector<Article> HttpClient::parseHomepage()
{
	return vector<Article>();
}
vector<Article> HttpClient::parsePickings()
{
	return vector<Article>();
}
vector<Article> HttpClient::parseCandidates()
{

	return vector<Article>();
}
vector<Article> HttpClient::parseNews()
{
	return vector<Article>();

}
vector<Article> HttpClient::parseMyposts()
{
	return vector<Article>();

}
vector<map<wstring, wstring> > HttpClient::parseRecommends()
{
	return vector<map<wstring, wstring> >();

}
vector<Article> HttpClient::parseMycomments()
{
	return vector<Article>();
}
vector<Article> HttpClient::parseMyvotes()
{
	return vector<Article>();
}