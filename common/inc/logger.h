#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <string>
#include "utils.h"

enum LoggerLevelEnum {NOLOG, INF, DBG, ERR};
using namespace std;

#define LOGIT(str) Logger::getInstance()->logIt(DBG, "", __FUNCTION__, __LINE__, str);
#define LOGS(str) {std::string s=str;Logger::getInstance()->logIt(DBG, "", __FUNCTION__, __LINE__, s);}
#define STACK(aStack) {std::string s;stackIntToString(aStack, s);Logger::getInstance()->logIt(DBG, "", __FUNCTION__, __LINE__, s);}
#define VECTOR(aVector) {std::string s;vectorIntToString(aVector, s);Logger::getInstance()->logIt(DBG, "", __FUNCTION__, __LINE__, s);}

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
