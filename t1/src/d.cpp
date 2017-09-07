/// \file enemytarget.cpp
/// \brief D class implementation
#include "b.h"
#include "d.h"

#include <iostream>
#include <string>
#include "appli.h"
#include "logger.h"


using namespace std;

/// \fn D::D(void)
/// constructor
/// 
D::D(int yi):B(0), y(yi)
{
    string sLog("D CONStructor - y =  " + std::to_string(y));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// destructor
D::~D(void)
{
    string sLog("D DEStructor");
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/**
 *\fn getBaseX
 */
int D::getBaseX()
{
    int test;
    test =  B::getX();//ok getX is public
    //test = B::x;//ko x is private
    //test = x;//ko
    test = xprotected;//ok x is protected   
    return test;
}

/**
 * \fn getBaseXProtected
 */
int D::getBaseXProtected()
{
    return B::xprotected;
}
