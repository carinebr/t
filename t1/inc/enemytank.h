#ifndef ENEMYTANK_H_INCLUDED
#define ENEMYTANK_H_INCLUDED
/// \file enemytank.h
/// \brief enemytank class header
#include <string>
#include "enemytarget.h"

using namespace std;

class EnemyTank : public EnemyTarget
{
    public :
        //constructor
        EnemyTank();
        /// copy constructor
        EnemyTank(const EnemyTank&);
        //destructor
        ~EnemyTank(void);
        size_t getEnemyTankCount();
    private:
        static size_t m_EnemyTankCounter;
};
#endif  //ENEMYTANK_H_INCLUDED
