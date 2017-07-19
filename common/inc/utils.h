#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
#include <stack>
#include <vector>

using namespace std;
/// \file utils.h
/// \brief utilities header
int get_random (int max);
void stackIntToString(stack<int>& S, string& Str);
void vectorIntToString(const vector<int>& S, string& Str);
#endif  //UTILS_H_INCLUDED

