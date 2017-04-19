#include "excepterr.h"
#include <cstdio>

ExceptErr::ExceptErr(int num, int level, const string& phrase, const string& module, int line)throw():
    m_num(num), m_level(level), m_phrase(phrase), m_module(module), m_line(line)
{
    char szLine[31 + 1];

    sprintf(szLine, ", - line: %d\n", line);
    m_phrase = m_phrase + "\"-  module: \"" + module + szLine;
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

