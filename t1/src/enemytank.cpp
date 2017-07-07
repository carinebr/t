/// \file enemytank.cpp
/// \brief EnemyTank class implementation

#include <iostream>
#include "appli.h"
#include "enemytank.h"
#include "excepterr.h"
#include "logger.h"

using namespace std;

size_t EnemyTank::m_EnemyTankCounter;

/// \fn EnemyTank::EnemyTank(void)
/// constructor
/// 
EnemyTank::EnemyTank(void)
{
    m_sClassName = "EnemyTank";
    m_EnemyTankCounter++;
    string sLog(className() + " CONStructor - num of enemy tanks: " + std::to_string(m_EnemyTankCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// \fn EnemyTank::EnemyTank(const EnemyTank&)
/// copy constructor
/// 
EnemyTank::EnemyTank(const EnemyTank&)
{
    m_sClassName = "EnemyTank";
    m_EnemyTankCounter++;  
    string sLog(className() + " COPY CONStructor - num of enemy tanks: " + std::to_string(m_EnemyTankCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// \fn EnemyTank::~EnemyTank(void)
/// destructor
EnemyTank::~EnemyTank(void)
{
    m_EnemyTankCounter--;
    string sLog(className() + " DEStructor - num of enemy tanks: " + std::to_string(m_EnemyTankCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/**
 * \fn getEnemyTankCount()
 * \brief returns the m_EnemyTankCounter member
 */
size_t EnemyTank::getEnemyTankCount() const
{
    return m_EnemyTankCounter;
}
