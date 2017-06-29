/// \file logger.cpp
/// \brief  application level data handling
#include <iostream>
#include <fstream>
#include "logger.h"
#include "excepterr.h"
#include "appli.h"

using namespace std;

static const string EMPTY_STRING;
/// \fn logger::logger()
/// \brief constructor
Logger::Logger(void)
{
    Appli * appliInstance = Appli::getInstance();
    m_sLogFile = appliInstance->getInivalue("logfile");
}


/// \fn Logger::~Logger() 
/// \brief destructor
Logger::~Logger(void)
{
    m_Instance = NULL;
}
/// \fn static Logger::getInstance()
/// \brief restricts the instantiation of the appli class to be singletone
Logger* Logger::getInstance()
{
    if (m_Instance == NULL)
        m_Instance = new Logger;
    return m_Instance;
}

