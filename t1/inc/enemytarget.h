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
        virtual ~EnemyTarget(void);
        size_t getEnemyTargetCount() const;
        virtual const string& className() const;
        EnemyTarget& operator=(const EnemyTarget& in_AnotherTArget);
        const string& getClassName() const{return m_sClassName;}
        void setClassName(const string& in_sClassName){m_sClassName = in_sClassName;}

    private:
        string m_sClassName;
        static size_t m_EnemyTargetCounter;
};
#endif  //ENEMYTARGET_H_INCLUDED
