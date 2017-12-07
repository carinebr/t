/// \file enemytarget.cpp
/// \brief D class implementation
#include "b.h"
#include "d.h"

#include <iostream>
#include <string>
#include "appli.h"
#include "logger.h"


using namespace std;
/**
 * \D()
 * \fn constructor
 */
D::D(): y(88)
{
    B::xprotected = 999;//ok - but ko in the initialized list since it is not a D member
    //B::x = 999;ko - x is private
    cout << "D constructor y set to " << y << endl;
}
/// \fn D::D(void)
/// constructor
/// 
D::D(int yi):y(yi)
{
    string sLog("D CONStructor - y =  " + std::to_string(y));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// destructor
D::~D()
{
    string sLog("D DEStructor");
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
    cout << "D destructor" << endl;
}

/**
 *\fn getBaseX  inutile B* pb = newD peut pb->getX()
 *              idem D d() peut d->getX()
 */
