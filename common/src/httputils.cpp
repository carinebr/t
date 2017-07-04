#include <iostream>
#include <curl/curl.h>
#include <pthread.h>
#include <unistd.h>
#include "httputils.h"
#include "excepterr.h"
#include "logger.h"
#include "utils.h"

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
static string sPostThis("kukuriku kukuriku POST");
static const int MAX_THREAD_NUMBER = 7;

int sendHttpRequestMthread(const string& in_sUrl)
{
    int i;

    pthread_t tid[7];
    curl_global_init(CURL_GLOBAL_ALL);

    for (i = 0; i < MAX_THREAD_NUMBER; i++)
    {
        pthread_create (&tid[i], NULL, sendHttpRequest, (void*) in_sUrl.c_str());
    }
    // wait for the thread execution end
    for(i=0; i< MAX_THREAD_NUMBER; i++)
    {
        pthread_join(tid[i], NULL);//without it, the main thread will end before the end of the http request
    }
    curl_global_cleanup();
    return 0;
}
void* sendHttpRequest(void* in_szUrl)
{
    string sUrl((const char*)in_szUrl);
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    Logger* theLogger = Logger::getInstance();

    sleep(get_random(3));//for more interest if multi threading
    curl = curl_easy_init();
    /* Check for errors */ 
    if(!curl)
    {
        string sErr = "curl_easy_init() failed for url : " + sUrl;
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sErr);
        return NULL;
    }
    curl_easy_setopt(curl, CURLOPT_URL, sUrl.c_str());
    //curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.co.il/");//seulement si get google ne recoit pas de post
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    //curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sPostThis.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, sPostThis.length());
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        string sErr = "curl_easy_perform() failed for url : " + sUrl;
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sErr);
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, curl_easy_strerror(res));
    }
    else
    {
        string sErr = "curl_easy_perform() succeeded for url : " + sUrl + " - resp : ";
        sErr += readBuffer; 
        theLogger->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sErr);
    }
    curl_easy_cleanup(curl);

    //std::cout << readBuffer << std::endl;
    
    return NULL;
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t written(nmemb*size);
    ((std::string*)userdata)->append(ptr, written);
    return written;
}
