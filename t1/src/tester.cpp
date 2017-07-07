/// \file tester.cpp
/// \brief functionnality testing implementation

#include <iostream>
#include "appli.h"
#include "tester.h"
#include "excepterr.h"
#include "enemytank.h"
#include "logger.h"

using namespace std;

/// \fn Tester::Tester(void)
/// constructor
/// 
Tester::Tester(void)
{
//    cout << "tester class constructor" <<endl;
}

/// \fn Tester::~Tester(void)
/// destructor
Tester::~Tester(void)
{
//    cout << "tester class destructor" <<endl;
    m_Instance = NULL;
}
/// \fn static Tester::getInstance()
/// \brief restricts the instantiation of the appli class to be singletone
Tester* Tester::getInstance()
{
    if (m_Instance == NULL)
        m_Instance = new Tester;
//    cout << "Tester::getInstance() invoqued" <<endl;
    return m_Instance;
}

/**
 * \fn Tester::testIt(const string& in_sWhichTest)
 * \brief launch a specific test or all the tests
 * \param[in] in_sWhichTest test to be launched, include all
 * \return 1 ok 0/ko
 */
int Tester::testIt(const string& in_sWhichTest)
{
    //todo get an appli instance
    //
    if (in_sWhichTest == "appli")
    {
        Appli * appliInstance = Appli::getInstance();//constructing an Appli object is impossible(private constructor).
        try
        {
            appliInstance->readIniFile();
        }
        catch(ExceptErr& e)
        {
            //todo ajouter a ExceptErr un methode pour ajouter la ligne a la pile. A utiliser a chaque catch(ExceptErr...
            e.addStackInfo(__FILE__, __FUNCTION__, __LINE__);
            throw;//handled in the invoker funct
        }
        catch(const exception& e)
        {
            throw;//handled in the invoker funct
        }
    }
    else if(in_sWhichTest == "inheritance")
    {
        string sLog;
        EnemyTarget enemyTarget1;
        EnemyTank enemyTank1;
        enemyTank1.setCommander("john");
        sLog = " tank1 commender : " + enemyTank1.getCommander();
        Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
        sLog = "num of targets after tank creation :" + enemyTank1.getEnemyTargetCount();
        Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
        EnemyTank enemyTank2;
        enemyTank2.setCommander("jack");
        sLog = " tank2 commander : " + enemyTank2.getCommander();
        Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
        
        enemyTank2 = enemyTank1;
        sLog = " tank2 commander : " + enemyTank2.getCommander();
        Logger::getInstance()->logIt(DBG, "", "", 0, sLog);

        sLog = "num of targets after tank creation :" + enemyTank1.getEnemyTargetCount();
        Logger::getInstance()->logIt(DBG, "", "", 0, sLog);
        EnemyTarget * ptrEnemyTank2 = new EnemyTank;
        sLog = "num of targets after second tank creation :" + std::to_string((*ptrEnemyTank2).getEnemyTargetCount());
        Logger::getInstance()->logIt(DBG, "", "", 0, sLog);

        delete ptrEnemyTank2;

    }
    return 1;
}
