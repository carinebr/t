#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED
/// \file tester.h
/// \brief tester class header
#include <string>
using namespace std;

class Tester
{
    public :
        static Tester* getInstance();
        //destructor
        ~Tester(void);
        int testIt(const string& in_sWhichTest);
        void testTemplate();
        void testFactory();
        void testNullClass();
        void testVectorErase();
        void testOddOccurencesInArrays();
    private:
        static Tester* m_Instance;
        //constructor
        Tester();
};
#endif  //TESTER_H_INCLUDED
