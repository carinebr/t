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
 * \fn stackIntToString(stack& S, string& S)
 * \brief set a string as a separated ' ' of the element of a stack<int>
 * \param[in] S
 * \param[out] the string
 */
void stackIntToString(std::stack<int> &Stack, std::string &theString)
{
    theString.clear();
    stack<int> S (Stack);
    while(!S.empty())
    {
        theString = theString + std::to_string(S.top());
        theString = theString + " ";
        S.pop();
    }
    if (!theString.empty())
        theString.pop_back();
}

/**
 * \fn vectorIntToString(stack& S, string& S)
 * \brief set a string as a separated ' ' of the element of a stack<int>
 * \param[in] S
 * \param[out] the string
 */
void vectorIntToString(const std::vector<int> &theVector, std::string &theString)
{
    theString.clear();
    vector<int>::const_iterator itr;

    for (itr = theVector.begin(); itr != theVector.end(); itr++)
    {
        theString = theString + std::to_string(*itr);
        theString = theString + " ";
    }
    if (!theString.empty())
        theString.pop_back();
}
