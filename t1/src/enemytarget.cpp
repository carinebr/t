/// \file enemytarget.cpp
/// \brief EnemyTarget class implementation

#include <iostream>
#include <string>
#include "appli.h"
#include "enemytarget.h"
#include "excepterr.h"
#include "logger.h"

using namespace std;

size_t EnemyTarget::m_EnemyTargetCounter;

/// \fn EnemyTarget::EnemyTarget(void)
/// constructor
/// 
EnemyTarget::EnemyTarget(void):m_sClassName("EnemyTarget")
{
    m_EnemyTargetCounter++;
    string sLog(className() + " CONStructor - num of enemy targets: " + std::to_string(m_EnemyTargetCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// \fn EnemyTarget::EnemyTarget(const EnemyTarget&)
/// copy constructor
/// 
EnemyTarget::EnemyTarget(const EnemyTarget&):m_sClassName("EnemyTarget")
{
    m_EnemyTargetCounter++;
    string sLog(className() + " COPY CONStructor - num of enemy targets: " + std::to_string(m_EnemyTargetCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// \fn EnemyTarget::~EnemyTarget(void)
/// destructor
EnemyTarget::~EnemyTarget(void)
{
    m_EnemyTargetCounter--;
    string sLog(className() + " DEStructor - num of enemy targets: " + std::to_string(m_EnemyTargetCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/**
 * \fn getEnemyTargetCount()
 * \brief returns the m_EnemyTargetCounter member
 */
size_t EnemyTarget::getEnemyTargetCount() const
{
    return m_EnemyTargetCounter;
}
/**
 * \fn classname()
 * \* brief return the class name
 */
const string& EnemyTarget::className() const
{
    return m_sClassName;
}

/**
 * \fn assignement operator
 * \brief assignement operator
 * \param[in] another EnemyTarget
 * \return EnemyTarget&
 */
EnemyTarget& EnemyTarget::operator=(const EnemyTarget& in_AnotherTarget)
{
    m_sClassName=in_AnotherTarget.getClassName();
    m_EnemyTargetCounter = in_AnotherTarget.getEnemyTargetCount();
    return *this;
}

