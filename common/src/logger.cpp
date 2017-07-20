/// \file logger.cpp
/// \brief  application level data handling
#include <iostream>
#include <fstream>
#include "logger.h"
#include "excepterr.h"
#include "appli.h"
#include "timeutils.h"

using namespace std;
static const string SPACE(" ");
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
/**
 * \fn Logger::logIt
 * \brief write one line in lthe loggger
 * \param [in] LoggerLevelEnum in_nLevel
 * \param [in] const string& in_sPhrase 
 * \return void
 */
void Logger::logIt(LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction, 
        int in_nLine, const string& in_sPhrase)
{
    ofstream logFile(m_sLogFile.c_str(), ios::out | ios::app);
    if (!logFile)
    {
        string sErr("open ");
        sErr.append(m_sLogFile).append(" failure");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    string sCurrentTime(currentDateTime()); 
    logFile << sCurrentTime << SPACE << in_sFile << SPACE << in_sFunction << SPACE
        << "L" << in_nLine << SPACE << in_sPhrase << endl; 
    logFile.close(); 
    return;
}

