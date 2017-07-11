#ifndef REAL_PERSON_H_INCLUDED
#define REAL_PERSON_H_INCLUDED

#include <string>
#include "date.h"
#include "person.h"

using namespace std;
/// \file logger.h
/// \brief log handler header
class RealPerson : public Person
{
    public :
        ///constructor
        RealPerson(const Date& in_BirthDate);
        ///destructor
        virtual ~RealPerson(void);
        virtual const Date& birthDate();
    private:
        Date m_BirthDate;
};
#endif  //REAL_PERSON_H_INCLUDED
