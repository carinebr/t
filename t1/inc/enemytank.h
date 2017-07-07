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
        size_t getEnemyTankCount() const;
        void setCommander(const string in_sCommander){m_sCommander = in_sCommander;}
        const string& getCommander() const {return m_sCommander;}
        EnemyTank operator=(const EnemyTank& in_theOtherTank);
    private:
        static size_t m_EnemyTankCounter;
        string m_sCommander;
};
#endif  //ENEMYTANK_H_INCLUDED
