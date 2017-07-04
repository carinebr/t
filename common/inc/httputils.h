#ifndef HTTPUTILS_H_INCLUDED
#define HTTPUTILS_H_INCLUDED

#include <string>

using namespace std;
/// \file httputils.h
/// \brief http utilities header

int sendHttpRequestMthread(const string& in_sUrl);
void* sendHttpRequest(void * ptr);
#endif  //HTTPUTILS_H_INCLUDED

