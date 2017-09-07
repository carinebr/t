/// \file b.cpp
/// \brief B class implementation
#include "b.h"

#include <iostream>
#include <string>
#include "appli.h"
#include "logger.h"


using namespace std;

/// \fn B::B(void)
/// constructor
/// 
B::B(int xi):xprotected(17), x(xi)
{
    string sLog("B CONStructor - x =  " + std::to_string(x));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// destructor
B::~B(void)
{
    string sLog("B DEStructor");
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/**
 * \fn getX()
 * \brief x gettor
 */
int B::getX()
{
    return x;
}
