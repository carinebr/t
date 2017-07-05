#ifndef ENEMYTARGET_H_INCLUDED
#define ENEMYTARGET_H_INCLUDED
/// \file enemytarget.h
/// \brief enemytarget class header
#include <string>
using namespace std;

class EnemyTarget
{
    public :
        //constructor
        EnemyTarget();
        /// copy constructor
        EnemyTarget(const EnemyTarget&);
        //destructor
        ~EnemyTarget(void);
        size_t getEnemyTargetCount();
    private:
        static size_t m_EnemyTargetCounter;
};
#endif  //ENEMYTARGET_H_INCLUDED
