#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <string>

enum LoggerLevelEnum {NOLOG, INF, DBG, ERR};
using namespace std;
/// \file logger.h
/// \brief log handler header
class Logger
{
    public :
        static Logger* getInstance();
        ///destructor
        ~Logger(void);
        void logIt(LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction, 
                int in_nLine, const string& in_sPhrase);
    private:
        static Logger* m_Instance;
        ///constructor
        Logger();
        string m_sLogFile;
};
#endif  //LOGGER_H_INCLUDED
