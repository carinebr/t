/// \file date.cpp
/// \brief functionnality testing implementation

#include "date.h"


/// \fn Date::Date(void)
/// constructor
/// 
Date::Date(const string& in_sDate):m_sDate(in_sDate)
{
}

/// \fn Date::~Date(void)
/// destructor
Date::~Date(void)
{
}

/**
 * \fn date::getDate
 * \brief getter for tje m_sDate member
 * \return the m_sDate
 */
const string& Date::getDate() const
{
    return m_sDate;
}

/**
 * \fn Date::Date(const Date& in_anotherDate)
 * \brief copy construtor
 */
Date::Date(const Date& in_anotherDate)
{
    m_sDate = in_anotherDate.m_sDate;
}
