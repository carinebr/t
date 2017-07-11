/// \file person.cpp
/// \brief functionnality testing implementation

#include "person.h"
#include "date.h"
#include "realperson.h"

/// \fn Person::makePerson(const Date&)
/// person factory
/// 
Person* Person::makePerson(const Date& in_Date)
{
    return new RealPerson(in_Date);
}

