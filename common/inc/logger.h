#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <string>

using namespace std;
/// \file logger.h
/// \brief log handler header
class Logger
{
    public :
        static Logger* getInstance();
        ///destructor
        ~Logger(void);
        void setLogFile(const string& in_sIniFile);
        const string& getInivalue(const string& in_sKey);
    private:
        static Logger* m_Instance;
        ///constructor
        Logger();
        string m_sLogFile;
};
#endif  //LOGGER_H_INCLUDED
