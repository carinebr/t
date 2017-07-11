#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>

using namespace std;


class Date;
/// \file logger.h
/// \brief log handler header
class Person
{
    public :
        ///destructor
        virtual ~Person(){};
        //factory to separate realPerson from the Person client sources
        static Person* makePerson(const Date& in_TheDate);
        virtual const Date& birthDate() = 0;
};
#endif  //PERSON_H_INCLUDED
