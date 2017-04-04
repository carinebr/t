#include "excepterr.h"

ExceptErr::ExceptErr(int num, const string& phrase, int level) throw() :m_num(num),m_phrase(phrase),m_level(level)
{
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

