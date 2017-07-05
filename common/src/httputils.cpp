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
static void* sendHttpRequest(void * in_HttpThreadInfo);

class HttpThreadInfo
{
    public:
        HttpThreadInfo();
        HttpThreadInfo(const string& in_sUrl);
        ~HttpThreadInfo();
        const string& getUrl(void);
        void logIt(LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction, 
                int in_nLine, const string& in_sPhrase);
    private:
        string m_sUrl;
        pthread_mutex_t m_CoutMutex;
        Logger* m_TheLogger;
};       
HttpThreadInfo::HttpThreadInfo()
{
    m_CoutMutex = PTHREAD_MUTEX_INITIALIZER;
    m_TheLogger = Logger::getInstance();
}

HttpThreadInfo::HttpThreadInfo(const string& in_sUrl):m_sUrl(in_sUrl)
{
    m_CoutMutex = PTHREAD_MUTEX_INITIALIZER;
    m_TheLogger = Logger::getInstance();
}
/**
 * \fn  HttpThreadInfo::logIt
 * \brief enveloppe logIt du logger pour gerer le mutex
 * \param[in] (LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction,
 *             int in_nLine, const string& in_sPhrase
 */
void HttpThreadInfo::logIt(LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction,
        int in_nLine, const string& in_sPhrase)
{
    pthread_mutex_lock(&m_CoutMutex);
    m_TheLogger->logIt(in_nLevel, in_sFile, in_sFunction, in_nLine, in_sPhrase);
    pthread_mutex_unlock(&m_CoutMutex);
}

HttpThreadInfo::~HttpThreadInfo()
{
}
const string & HttpThreadInfo::getUrl(void)
{
    return m_sUrl;
}
int sendHttpRequestMthread(const string& in_sUrl)
{
    int i;
    string* pStrHttpRet = NULL;

    
    pthread_t tid[7];
    curl_global_init(CURL_GLOBAL_ALL);

    HttpThreadInfo httpThreadInfo(in_sUrl);
    for (i = 0; i < MAX_THREAD_NUMBER; i++)
    {
        pthread_create (&tid[i], NULL, sendHttpRequest, (void*) &httpThreadInfo);
    }
    // wait for the thread execution end. without it, the main thread will end before the end of the http request
    for(i=0; i< MAX_THREAD_NUMBER; i++)
    {
        pthread_join(tid[i], (void**)&pStrHttpRet);
        if (pStrHttpRet != NULL)
            httpThreadInfo.logIt(DBG, __FILE__, __FUNCTION__, __LINE__, *(string*)pStrHttpRet + " - thread: " 
                    + std::to_string(i));
    }
    if (pStrHttpRet != NULL)
        delete(pStrHttpRet);
    curl_global_cleanup();
    return 0;
}
static void* sendHttpRequest(void* in_HttpThreadInfo)
{
    string sUrl;
    string* pStringErr = new(string);
    sUrl = ((HttpThreadInfo*)in_HttpThreadInfo)->getUrl();
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    sleep(get_random(3));//for more interest if multi threading
    curl = curl_easy_init();
    /* Check for errors */ 
    if(!curl)
    {
        *pStringErr = "curl_easy_init() failed for url : " + sUrl;
        ((HttpThreadInfo*)in_HttpThreadInfo)->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, *pStringErr);
        return NULL;
    }
    curl_easy_setopt(curl, CURLOPT_URL, sUrl.c_str());
    //curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.co.il/");//seulement si get google ne recoit pas de post
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    //curl_easy_setopt(curl, CURLOPT_POST, 1L);//inutile si la suite 
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sPostThis.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, sPostThis.length());
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        *pStringErr = "curl_easy_perform() failed for url : " + sUrl;
        ((HttpThreadInfo*)in_HttpThreadInfo)->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, *pStringErr);
        ((HttpThreadInfo*)in_HttpThreadInfo)->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, curl_easy_strerror(res));
    }
    else
    {
        *pStringErr = "curl_easy_perform() succeeded for url : " + sUrl + " - resp : ";
        *pStringErr += readBuffer; 
        ((HttpThreadInfo*)in_HttpThreadInfo)->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, *pStringErr);
    }
    curl_easy_cleanup(curl);

    pthread_exit((void*)pStringErr);//to be freed by the invoker
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t written(nmemb*size);
    ((std::string*)userdata)->append(ptr, written);
    return written;
}
