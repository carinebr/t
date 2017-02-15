#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED

/// \file tester.h
/// \brief tester class header

class Tester
{
    public :
        static Tester* getInstance();
        //destructor
        ~Tester(void);
    private:
        static Tester* m_Instance;
        //constructor
        Tester();
};
#endif  //TESTER_H_INCLUDED
