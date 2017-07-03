#include <iostream>
#include <curl/curl.h>
#include "httputils.h"
#include "excepterr.h"
#include "logger.h"

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
static string sPostThis("kukuriku kukuriku POST");
int sendHttpRequest(const string& in_sUrl)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    Logger* theLogger = Logger::getInstance();
    curl = curl_easy_init();
    /* Check for errors */ 
    if(!curl)
    {
        string sErr = "curl_easy_init() failed for url : " + in_sUrl;
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sErr);
        return 0;
    }
    curl_easy_setopt(curl, CURLOPT_URL, in_sUrl.c_str());
    //curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.co.il/");//seulement si get
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    //curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sPostThis.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, sPostThis.length());
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        string sErr = "curl_easy_perform() failed for url : " + in_sUrl;
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sErr);
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, curl_easy_strerror(res));
    }
    else
    {
        string sErr = "curl_easy_perform() succeeded for url : " + in_sUrl + " - resp : ";
        sErr += readBuffer; 
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sErr);
    }
    curl_easy_cleanup(curl);

    //std::cout << readBuffer << std::endl;
    
    return 0;
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t written(nmemb*size);
    ((std::string*)userdata)->append(ptr, written);
    return written;
}
