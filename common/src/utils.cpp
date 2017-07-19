#include <iostream>
#include <curl/curl.h>
#include <pthread.h>
#include "httputils.h"
#include "excepterr.h"
#include "logger.h"
#include "utils.h"

int get_random (int max)
{
    double val;

    val = (double) max * rand ();
    val = val / (RAND_MAX + 1.0);

    return ((int) val);
}

/**
 * \fn stackToString(stack& S, string& S)
 * \brief set a string as a separated ' ' of the element of a stack<int>
 * \param[in] S
 * \param[out] the string
 */
void stackIntToString(std::stack<int> &Stack, std::string &Str)
{
    Str.clear();
    stack<int> S (Stack);
    while(!S.empty())
    {
        Str = Str + std::to_string(S.top());
        Str = Str + " ";
        S.pop();
    }
    if (!Str.empty())
        Str.pop_back();
}
