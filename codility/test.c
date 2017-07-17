#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>

int test ()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
      
    printf("\ntest function\n");
    return 0;
}
