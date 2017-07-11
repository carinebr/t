/// \file realperson.cpp
/// \brief functionnality testing implementation

#include "person.h"
#include "date.h"
#include "realperson.h"

/// \fn RealPerson::RealPerson(void)
/// constructor
/// 
RealPerson::RealPerson(const Date& in_Date):m_BirthDate(in_Date)
{
}

/// \fn Person::~Person(void)
/// destructor
RealPerson::~RealPerson(void)
{
}

const Date& RealPerson::birthDate()
{
    return m_BirthDate;
}
