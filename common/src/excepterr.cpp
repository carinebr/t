#include "excepterr.h"
#include <cstdio>

ExceptErr::ExceptErr(int num, int level, const string& phrase, const string& module, const string& function, int line)throw():
    m_phrase(phrase) 
{
    char szLine[31 + 1];

    sprintf(szLine, ", - line: %d\n", line);
    m_phrase = "exception!!: " + m_phrase + "\nmodule: " + module +  " - function: " + function + "()" + szLine;
}

const char* ExceptErr::what() const throw()
{
    return m_phrase.c_str();
}

int ExceptErr::getLevel() const throw()
{
    return m_level;
}

ExceptErr::~ExceptErr() throw()
{
}

void ExceptErr::addStackInfo(const char* module, const char* function, int line)
{
    char szLine[31 + 1];

    if (module == NULL || function == NULL || line < 1)
        return;//bad use for the function
    sprintf(szLine, " - line: %d", line);
    m_phrase =  m_phrase + "module: " + module + " - function: " + function + "() " + szLine + "\n";
}
