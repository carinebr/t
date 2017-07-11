#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>

using namespace std;
/// \file logger.h
/// \brief log handler header
class Date
{
    public :
        ///constructor
        Date(const string& in_sDate);
        ///destructor
        ~Date(void);
        const string& getDate() const;
        ///copy constructor
        Date(const Date& in_anotherDate);
    private:
        string m_sDate;
};
#endif  //DATE_H_INCLUDED
