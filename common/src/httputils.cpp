#include <iostream>
#include <curl/curl.h>
#include "httputils.h"

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
int sendHttpRequest(const string& in_sUrl)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    
    curl = curl_easy_init();
    /* Check for errors */ 
    if(!curl) {
        cout << "curl_easy_init() failed" << endl;
        return 0;
    }
    curl_easy_setopt(curl, CURLOPT_URL, in_sUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
    
    return 0;
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t written(nmemb*size);
    ((std::string*)userdata)->append(ptr, written);
    return written;
}
