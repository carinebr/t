/// \file enemytarget.cpp
/// \brief EnemyTarget class implementation

#include <iostream>
#include "appli.h"
#include "enemytarget.h"
#include "excepterr.h"
#include "logger.h"

using namespace std;

size_t EnemyTarget::m_EnemyTargetCounter;

/// \fn EnemyTarget::EnemyTarget(void)
/// constructor
/// 
EnemyTarget::EnemyTarget(void)
{
    m_EnemyTargetCounter++;
    string sLog("tester class CONStructor - num of enemy targets: " + std::to_string(m_EnemyTargetCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// \fn EnemyTarget::EnemyTarget(const EnemyTarget&)
/// copy constructor
/// 
EnemyTarget::EnemyTarget(const EnemyTarget&)
{
    m_EnemyTargetCounter++;
    string sLog("tester class COPY CONStructor - num of enemy targets: " + std::to_string(m_EnemyTargetCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/// \fn EnemyTarget::~EnemyTarget(void)
/// destructor
EnemyTarget::~EnemyTarget(void)
{
    m_EnemyTargetCounter--;
    string sLog("tester class DEStructor - num of enemy targets: " + std::to_string(m_EnemyTargetCounter));
    Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
}

/**
 * \fn getEnemyTargetCount()
 * \brief returns the m_EnemyTargetCounter member
 */
size_t EnemyTarget::getEnemyTargetCount()
{
    return m_EnemyTargetCounter;
}
