#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED
/// \file tester.h
/// \brief tester class header
#include <string>
using namespace std;

class Tester
{
    public :
        void testFunctor();
        void testRef();
        void testFactorsNbr();
        void testMoc1();
        void testMoc2();
        void testMoc3();
        static Tester* getInstance();
        //destructor
        ~Tester(void);
        void testMisc();
        void testDemoCodility();
        void testLeaderSort();
        void testBitWiseOps();
        void testBinaryGap2();
        int testIt(const string& in_sWhichTest);
        void testVikiSense();
        void testBD();
        void testPassingCars();
        void testTemplate();
        void testFactory();
        void testNullClass();
        void testVectorErase();
        void testOddOccurencesInArrays();
        void testOddOccurencesInArrays2();
        void testPermMissingElemLessons3();
        void testPermMissingElem2();
        void testFrogJmpLessons3();
        void testFrogJmp2();
        void testMissingIntegerLesson4();
        void testCountDivLesson5();
        void testDistinctLesson6();
        void testBracketsLesson7();
        void testDomminatorLesson8();
        void testMaxProfitLesson9();
        void testMinPerimRectangle();
        void testCountSemiPrimesLesson11();
        void testChocolatesLesson12();
        void testGcd(); 
        void testFibo();
        void testBinSearchLe();//Le ie Less or Equal
        void testCountAbsolute();
        void testBinaryGap();
        void testCyclicRotation();
        void testTapeEquilibriumLesson3();
        void testPermLesson4();
        void testFrogLesson4();
        void testCarsLesson5();
        void testEqu();
        void testMaxProd();
        void testEquilibrium();
        //==================
        void testAAA();
        void testBBB();
        void testCCC();
        void testDDD();
        void testEEE();
        void testFFF();
        void test111();
        void test222();
        void test333();
        void test444();
        //==================
        void testTcp();
        void testRoundForest();


    private:
        static Tester* m_Instance;
        void testTcpServer();
        void testTcpClient();
        //constructor
        Tester();
};
#endif  //TESTER_H_INCLUDED
