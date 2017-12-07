/// \file b.cpp
/// \brief B class implementation
#include "b.h"

#include <iostream>
#include <string>
#include "appli.h"
#include "logger.h"


using namespace std;

/**
 * \fn B()
 * \brief construuctor
 */
B::B():x(77)
{
    cout << "B() constructor private x set to 77" << endl;
}
/// \fn B::B(void)
/// constructor
/// 
B::B(int xi):xprotected(17), x(xi)
{
    cout << "B(int) constructor xprotected set to 17, x set to " << xi << endl;
}

/// destructor
B::~B(void)
{
    string sLog("B DEStructor");
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
    cout << "B destructor" << endl;
}

