#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QThread>

#include "XmlParser.h"

class HttpClient : QThread
{
	Q_OBJECT

public:
	HttpClient();
	~HttpClient(void);

private:

};


#endif


