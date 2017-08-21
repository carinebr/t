/// \file tester.cpp
/// \brief functionnality testing implementation

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include "appli.h"
#include "tester.h"
#include "excepterr.h"
#include "enemytank.h"
#include "logger.h"
#include "arraystmpl.h"
#include "person.h"
#include "date.h"
#include "tcpserver.h"
#include "tcpclient.h"
#include "roundforest.h"

using namespace std;

int solutionEquilibrium(vector<int> &A);
int solutionBinaryGap(int i);
int solutionTestOddOccurencesInArrays(vector<int> &A);
int solutionPermMissingElemLessons3(vector<int>& A);
int solutionFrogJmpLesson3(int x, int y, int d);
int solutionMissingIntegerLesson4(vector<int>& A);
int solutionContDivLesson5(int A, int B, int K);
int solutionDistinctLesson6(vector<int>& A);
int solutionBracketsLesson7(const string& S);
int solutionDomminatorLesson8(vector<int> &A);
int solutionMaxSlice(vector<int>& A);
int solutionMaxProfitLesson9(vector<int> &A);
int solutionMinPerimRectangleLesson10(int N);
int solutionChocolatesLesson12(int M, int N);
vector<int> solutionCyclicRotation(vector<int> &A, int K);
int solutionTapeEquilibriumLesson3(vector<int> &A);
int solutionPermLesson4(vector<int> &A);
int solutionFrogLesson4(int X, vector<int> &A);
int solutionCarsLesson5(vector<int>&);
int solutionEqu(vector <int> &A);
int solutionMaxProd(vector<int> &A);
//====================================
int solution111(vector<int> &A);
int solution222(string &E, string &L);
int solution333(int N);
//====================================

vector<int> solutionCountSemiPrimesLesson11(int N, vector<int> &P,
        vector<int>&Q);
vector<int> factorizationArray(int n);
vector<int> factorization(int x, vector<int>F);
int gcd(int a, int b, int res);//grand commun diviseur a utiliser quand res == 1
long long int fibo(int n);
int binSearchLe(vector<int> &A, int x);
int countAbsolute(vector <int> &A);
void binaryBitsLoop(int N);

    
    
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

/**
 *\fn testTemplate
 \*\brief test les template
 *
 */
void Tester::testTemplate()
{
    int a = 7, b = 5;

    Logger::getInstance()->logIt(DBG, "", "", 0, to_string(aSimpleTmplFunc<int>(a, b)));
    
    int arg[] = {1245, 345, 0, -6, 5};
    Logger::getInstance()->logIt(DBG, "", "", 0, to_string(average<int, double>(arg, 5)));

    int c(8), d(123);
    Logger::getInstance()->logIt(DBG, "", "", 0, to_string(minimum<int, int>(c, d)));

    double e(123.678), dd(124.567);
    Logger::getInstance()->logIt(DBG, "", "", 0, to_string(minimum<double, double>(e, dd)));

    double ee(123.678);
    int ddd(122.567);
    Logger::getInstance()->logIt(DBG, "", "", 0, to_string(minimum<double, int>(ee, ddd)));

    std::vector<int> myVec;
    myVec.push_back(14);
    myVec.push_back(16);
    myVec.push_back(17);
    myVec.push_back(18);
    myVec.push_back(19);

    Logger::getInstance()->logIt(DBG, "", "", 0, to_string(average2<int, double>(myVec))); 
}

class NullClass
{
    public:
        template <class T>
            operator T*() const {return 0;}
        operator NullClass* () const {return 0;}
};
/**
 *\fn testTemplate
 \*\brief test les template
 *
 */
void Tester::testNullClass()
{
    //const NullClass nullObject;
    //les 2 lignes suivantes sont equivalantes
    //NullClass* ncPtr = nullObject.operator NullClass*();
    //ncPtr = *nullObject;
}

/**
 *\fn testFactory
 \*\brief test le factory de Person
 *
 */
void Tester::testFactory()
{
    Date aBirthDay("une date de naisance");
    Person* pPerson = Person::makePerson(aBirthDay);
    Logger::getInstance()->logIt(DBG, "", "", 0, pPerson->birthDate().getDate());
    delete pPerson;
}
class MyClass
{
    public:
        MyClass(){Logger::getInstance()->logIt(DBG, "", "", 0, "MyClass CONSTRUCTOR");}
        ~MyClass(){Logger::getInstance()->logIt(DBG, "", "", 0, "MyClass DESTRUCTOR");}
};

/**
 *\fn testTemplate
 \*\brief test la creation de templates particulierement; un vector de pointeur de class passe t il par le 
 *        destructeur au moment de erase
 */
void Tester::testVectorErase()
{
    std::vector<MyClass*> v;
    for( int i=0; i< 5; i++)
        v.push_back(new MyClass);
    int i = 0;
    for(std::vector<MyClass*>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        delete(*itr);
        Logger::getInstance()->logIt(DBG, "", "", 0, std::to_string(i));
        i++;
    }
    v.clear();
    std::vector<MyClass> v2;
    Logger::getInstance()->logIt(DBG, "", "", 0, "\n2eme partie\n");
    MyClass mc;
    Logger::getInstance()->logIt(DBG, "", "", 0, "2eme partie avant pushback");
    v2.push_back(mc);
    v2.clear();
    Logger::getInstance()->logIt(DBG, "", "", 0, "2eme partie apres clear");
}

/**
 * \fn Tester::testOddoccurencesInArrays()
 * \brief lesson 2 in codility.com
 */
void Tester::testOddOccurencesInArrays()
{
    int myA[] = {9, 3, 9, 3, 9, 7, 9};
    vector<int> A(myA, myA+7);
    VECTOR(A)
    LOGS("solu odd: " + to_string(solutionTestOddOccurencesInArrays(A)));
    //8 4 8 5 4 5 6 6 7
}
/**
 * \fn solutionTestOddOccurencesInArrays
 * \brief solution of testOddOccurencesInArrays
 * \param[in] vector<int> &A
 */
int solutionTestOddOccurencesInArrays(vector<int> &A)
{
    size_t i, S(A.size());
//#define LOGS(STR) 
    if (S == 1)
        return A[0];
    std::sort(A.begin(), A.end());
    if (A[S-1] != A[S-2])
        return A[S - 1];
    for(i = 0; i < A.size()-1; i++)
    {
        if (A[i] == A[i+1])
        {
            i++;
            continue;
        }
        else
        {
            return A[i];
        }
    }
    return 0;
}

/**
 * \fn Tester::testPermMissingElemLessons3
 * \brief test lessons 3 codility.com
 */
void Tester::testPermMissingElemLessons3()
{
    int myA[]={2, 3, 4, 5};
    vector<int> A(myA, myA + 4);
    VECTOR(A);
    LOGS("missing: " + to_string(solutionPermMissingElemLessons3(A)));
}

/**
 * \fn solutionPermMissingElemLessons3
 * \brief codility lessons 3
 * \param[in] const vectoor<int> A
 * \return the missing element
 */
int solutionPermMissingElemLessons3(vector<int> &A)
{
    size_t i;

    if (A.size() == 0)
        return 0;
    std::sort(A.begin(), A.end());
    if (A.size() == 1)
    {
        if (A[0] == 1)
            return 2;
        else
            return 1;
    }
    if (A[0] != 1)
        return 1;
    for(i = 0; i < A.size() - 1; i ++)
    {
        if (A[i+1] != A[i] + 1)
        {
            return A[i] + 1;
        }
    }
    return A[A.size()-1] + 1;
}

/**
 * \fn testFrogJmpLessons3()
 */
void Tester::testFrogJmpLessons3()
{
    solutionFrogJmpLesson3(1, 2, 3);
    solutionFrogJmpLesson3(1, 10, 3);
    solutionFrogJmpLesson3(1, 100, 3);
    solutionFrogJmpLesson3(1, 2, 10);
    solutionFrogJmpLesson3(1, 1, 3);
} 
/**
 * \fn solutionFrogJmpLesson3
 * \brief frog jump
 * \param[in] X, Y, D
 * \return number of steps
 * Vraie solutionp; pas de loop = res = x-y / d (eventuellement + 1)
 */

int solutionFrogJmpLesson3(int X, int Y, int D)
{
    int steps(0);

    int diff(Y-X);
    if (diff == 0)
        return 0;
    if (diff%D ==0)
        steps = (diff)/D;
    else
        steps = (diff/D) + 1;
    //LOGS("X: " + std::to_string(X) + " Y: " + std::to_string(Y) + " D: "
    //        + std::to_string(D) + " steps: " + std::to_string(steps));
    return steps;
}

/**
 * \fn Tester::testMissingIntegerLesson4()
 * \brief test codility lesson 4 MissingInteger
 */
void Tester::testMissingIntegerLesson4()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(6);
    A.push_back(4);
    A.push_back(2);
    solutionMissingIntegerLesson4(A);
    return;
}

/**
 * \fn solutionMissingIntegerLesson4(vector<int> &A)
 *     l'idee est d'utiliser une struct vector d'aide qui en passamt sur le premier vector
 *     ecrit l'info du 1er vector dans le 2eme
 */
int solutionMissingIntegerLesson4(vector<int> & A)
{
//#define LOGS(STR)
    size_t i, size_a(A.size());
    //utiliser un array <bool>
    vector<bool> B(size_a + 1, false);
    for (i=0; i< size_a + 1; i++)
    {
        if (A[i]> 0 && A[i] <= static_cast<int> (size_a + 1))
        {
            LOGS("A[i]: " + std::to_string(A[i]));
            B[A[i]-1] = true;
        }
    }
//    for (i = 0; i < B.size() + 1; i++)
//        LOGS(std::to_string(B[i]));
    for (i=0; i<B.size(); i++)
    {
        if (B[i] == false)
        {
            LOGS(std::to_string(i+1));
            return i+1;
        }
    }
    return 0;
}

/**
 * \fn testCountDivLesson5
 */
void Tester::testCountDivLesson5()
{
    solutionContDivLesson5(8, 34, 3);
    solutionContDivLesson5(6, 11, 2);
    solutionContDivLesson5(6, 7, 2);
    solutionContDivLesson5(6, 6, 2);
    solutionContDivLesson5(6, 11, 13);
}

/**
 * \fn solutionContDivLesson5
 */
int solutionContDivLesson5(int A, int B, int K)
{
//#define LOGS(s)
    int sum(0);
    for (int i = A; i < B+1; i++)
        if (i%K == 0)
            sum++;
    LOGS("A: " + std::to_string(A) + ", B: " + std::to_string(B) +
            ", K: " + std::to_string(K) + " - result: "
            + std::to_string(sum));
    return sum;
}

/**
 * \fn testDistinctLesson6
 * \brief
 */
void Tester::testDistinctLesson6()
{
    int myA[] = {2, 1, 1, 2, 3, 1};
    vector<int> A (myA, myA + 6);
    solutionDistinctLesson6(A);

    A.clear();
    solutionDistinctLesson6(A);

    A.push_back(3);
    solutionDistinctLesson6(A);
    A.push_back(2);
    solutionDistinctLesson6(A);
}

/**
 * \fn solutionDistinctLesson6
 * \brief return the number of distinct value
 */
int solutionDistinctLesson6(vector<int>& A)
{
    size_t i;
    int res(1);
    
    if(A.size() == 0)
        return 0;
    vector<int> B(A);
    std::sort(B.begin(), B.end());
    
    for (i = 1; i < B.size(); i++)
    {
       if (B[i-1]!=B[i])
          res++;
    } 
    //LOGS("res: " + std::to_string(res));
    return res;
}

/**
 * \fn Tester::testBracketsLesson7()
 * \brief
 */
void Tester::testBracketsLesson7()
{
    string S;

    S = "";
    solutionBracketsLesson7(S);

    S = "e";
    solutionBracketsLesson7(S);

    S = "()";
    solutionBracketsLesson7(S);

    S = "glfkj(jkhl0)";
    solutionBracketsLesson7(S);

    S = "]sdfsaf";
    solutionBracketsLesson7(S);

    S = ")(";
    solutionBracketsLesson7(S);

    S = "hfklh[";
    solutionBracketsLesson7(S);

    S = "(";
    solutionBracketsLesson7(S);

    S = ")";
    solutionBracketsLesson7(S);

    S = "g(fdhksfh[dfsadf[dfas]fasd]fsdaf(){[]})";
    solutionBracketsLesson7(S);

    S = "";
    solutionBracketsLesson7(S);
}

/**
 * \fn solutionBracketsLesson7()
 * \brief verify good nesting of a string
 */
int solutionBracketsLesson7(const string& S)
{
    stack<char> sc;
    size_t i;
    for (i = 0; i< S.size(); i++)
    {
        char c = S[i];
        if (c == '[' || c == '{' || c == '(')
            sc.push(c);
        else if (c == ']' || c == '}' || c == ')')
        {
            if (sc.empty())
                 return 0;
            else
            {
                if (c == ']')
                {
                    if (sc.top() != '[')
                        return 0;
                    else
                        sc.pop();
                }
                else if (c == '}')
                {
                    if (sc.top() != '{')
                        return 0;
                    else
                        sc.pop();
                }
                else if (c == ')')
                {
                    if (sc.top() != '(')
                        return 0;
                    else
                        sc.pop();
                }
            }
        }
        else
            continue;
    }       
//    if (sc.size() == 0)
//    {
//        LOGS(S + " OK!");
//    }
//    else
//    {
//        LOGS(S + " KO!");
//    }
    return sc.size() == 0;
}

/**
 * \fn testDomminatorLesson8()
 * \brief
 */
void Tester::testDomminatorLesson8()
{
    int myA[] = {3, 2, 4, 1, 5, 1, 3, 2, 3, 3, 5678, 3, 6, 3, 3, 3, 3};
    size_t i;
    vector<int> A(myA, myA + 17);
    for (i = 0; i< A.size(); i++)
    {
        LOGS(std::to_string(A[i]));
    }
    LOGS("index: " + std::to_string(solutionDomminatorLesson8(A)));
}

/**
 * \fn solutionDomminatorLesson8()
 * \brief minimalize the stones for building a wall
 */
int solutionDomminatorLesson8(vector<int> &A)
{
    stack<int> S;
    int val;
    size_t i, index;

    for (i = 0; i< A.size(); i++)
    {
        if (S.empty())
        {
            S.push(A[i]);
        }
        else
        {
            val = S.top();
            if (A[i] == val)
            {
                S.push(A[i]);
            }
            else
            {
                S.pop();
            }
        }
    }

    if (S.empty())
        return -1;
    //int leader = -1;
    size_t counter(0);

    for  (i = 0; i < A.size(); i++)
    {
        if (S.top() == A[i])
        {
            counter ++;
            index = i;
        }
    }
    if (counter> A.size()/2)
        return index;
    return -1;
}

/**
 * \fn testMaxProfitLesson9
 * \brief
 */
void Tester::testMaxProfitLesson9()
{
    int myA[] = {10, 8, 9, 13, 6, 11};
    vector<int> A(myA, myA + 6);//<<<<<< + le nbr d'elements
    VECTOR(A);
    LOGS("max profit: " + std::to_string(solutionMaxProfitLesson9(A)));
}

/**
 * \fn solutionMaxProfitLesson9()
 * \brief test le max profit d 'une liste de prix
 */
int solutionMaxProfitLesson9(vector<int>& A)
{
    //transformer en vecteur de gain/lost
    vector<int> B;
    size_t i;
    for (i = 1; i <A.size(); i++)
    {
        B.push_back(A[i] - A[i-1]);
        LOGS(std::to_string(B[i-1]));
    }
    //trouver le max slice            
    return(solutionMaxSlice(B));
}

/**
 * \fn maxSlice()
 * \brief rend la somme max d'une section du vector
 */
int solutionMaxSlice(vector<int>& A)
{
    int max_ending(0), max_slice(0);
    vector<int>::iterator itr;
    for (itr = A.begin(); itr != A.end(); itr++)
    {
       max_ending = max(0, max_ending + *itr);
       max_slice = max(max_slice, max_ending);
    }
    return max_slice;
}

/**
 * \fn Tester::testMinPerimRectengle
 * \brief
 */
void Tester::testMinPerimRectangle()
{
    int N(1234);//101 got 40 expected 204
    LOGS("area: " + std::to_string(N));
    solutionMinPerimRectangleLesson10(N);
    LOGS("perim :" 
            + std::to_string(solutionMinPerimRectangleLesson10(N)));
}

/**
 * \fn solutionMinPerimRectangleLesson10()
 * \brief return the min perimeter for a rectangle of surface N
 * \param[in] N surface
 */
int solutionMinPerimRectangleLesson10(int N)
{
    int i(1), P((N+1)*2), tmp;

    while(N/i >= i)
    {
        if (N%i == 0)
        {
            tmp = (i + N/i)*2;
            if (P == 0)
                P = tmp;//first result 1* N
            if (tmp < P)
                P = tmp;
        }
        i++;
    }
    return P;
}

/**
 * \fn testCountSemiPrimesLesson11
 * \brief
 */
void Tester::testCountSemiPrimesLesson11()
{
    int myP[] = {1, 4, 16};
    int myQ[] = {26, 10, 20};
    vector<int> P(myP, myP + 3);
    vector<int> Q(myQ, myQ + 3);

    VECTOR(P);
    VECTOR(Q);
    VECTOR(solutionCountSemiPrimesLesson11(26, P, Q));
}

/**
 * \fn solutionCountSemiPrimesLesson11
 * \brief give the number of semiprimes between 2 matching elements of 2 vectors
 */
vector<int> solutionCountSemiPrimesLesson11(int N, vector<int>&P, vector<int>&Q)
{
    vector<int> R, SP;
    size_t i;
    int num;
    int counter(0);
    vector<int>::iterator itr;

    //vecteur des semiprime number jusqu'a N
    for (num = 4; num<=N; num++)
    {
        vector<int> F(factorizationArray(num));
        if (factorization(num, F).size() == 2)
            SP.push_back(num);
    }
    //VECTOR(SP);
    for(i = 0; i < P.size(); i++)
    {
        counter = 0;
        //donnee un range P[i] - Q[i] iterer sur SP
        for (itr = SP.begin(); itr != SP.end(); itr ++)
        {
            if (*itr > Q[i])
                break;
            if (*itr < P[i])
                continue;
            counter ++;
        }
        R.push_back(counter);
    }
    return R;
}

/**
 * \fn factorizationArray
 * \brief rend tous les semi prime numbers sous de 2 a n
 */
vector<int> factorizationArray(int n)
{
    vector<int> F(n + 1, 0);
//    VECTOR(F);
    int i(2), k;
    while (i*i <= n)
    {
       if (F[i] == 0)
       {
           k = i * i;
           while (k <= n)
           {
               if (F[k] == 0)
                   F[k] = i;
               k += i;
           }
       }
       i += 1;
    }
    return F;
}

/**
 * \fn factorization
 * \brief rend pour n les chiffres premiers < n qui factorize n
 *  (dont la multiplication est n. Doit etre appele sur le vecteur fourni
 *  par factorizationArray(int n)
 */
vector<int> factorization(int x, vector<int>F)
{
    vector<int> primeFactors;
    while (F[x] > 0)
    {
        primeFactors.push_back(F[x]);
        x = x/F[x];
    }
    primeFactors.push_back(x);
    return primeFactors;
}

/**
 * \fn gcd 
 * \brief rend le + grand diviseur commun de a et b. res ==1
 */
int gcd(int a, int b, int res = 1)
{
    if (a == b)
        return res * a;
    else if ((a % 2 == 0) && (b % 2 == 0))
        return gcd(a / 2, b / 2, 2 * res);
    else if (a % 2 == 0)
        return gcd(a / 2, b, res);
    else if (b % 2 == 0)
        return gcd(a, b / 2, res);
    else if (a > b)
        return gcd(a - b, b, res);
    else
        return gcd(a, b - a, res);
    return 0;
}

/**
 *\fn Tester::testGcd()
 *\brief test interactivement gcd
 */
 void Tester::testGcd()
{
    int a, b;
    while (1)
    {
        cout << "input 2 numbers! stop by C-c " ; 
        cin >> a >>b;
        cout << "gcd of " << a << " and " << b << " is "
            << gcd(a, b, 1) << endl; 
    }
    return; 
}

/**
 * \fn testChocolatesLesson12()
 * \brief
 */
void Tester::testChocolatesLesson12()
{
    int M, N;
    //while (1)
    {
        //cout << endl << "enter M (jump) and N (number of chocolates) : ";
        //cin >> M >> N;
        M = 10; N = 34560;
        cout << "number of eaten : " << solutionChocolatesLesson12(M, N)
            << endl;
    }
}

/**
 * \solutionChocolatesLesson12()
 * \brief N number of pieces, M jump, returns the eaten
 */
int solutionChocolatesLesson12(int M, int N)
{
    return N/gcd(M, N, 1);
}

/**
 * \solutionChocolatesLesson12()
 * \brief N number of pieces, M jump, returns the eaten
 */
int solutionChocolatesLesson12_2(int M, int N)
{
    vector <int> V(N, 0);
    int i(0), counter(0);
    while (1)
    {
        if (V[i] == 1)
            break;
        V[i] = 1;//flag it as eaten
        counter ++;
        //jum to the next
        i = i + M;
        if (i > N-1)
            i = i % N;
    }
    return counter;
}

/**
 * \fn Tester::testFibo
 */
void Tester::testFibo()
{
    int n;

    while (1)
    {
        cout << "testFibo enter n :";
        cin >> n;
        cout << endl << "the fibo number is : " <<  fibo(n) << endl;
    }
}

/**
 * \fn fibo
 * \brief return the fibo number of n
 */
long long int fibo(int n)
{
    int i;

    vector <long long int> fib(n + 2, 0);
    fib[1] = 1;
    for (i = 2; i < n+1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

/**
 * \fn Tester::testBinSearchLe
 * \brief
 */
void Tester::testBinSearchLe()
{
    int x;
    int myA[] = {2, 4, 8, 567, 1, 45, 345, 456, 654, 321, 11, 12};
    vector<int> A(myA, myA+12);
    std::sort(A.begin(), A.end());
    VECTOR(A);
    while(1)
    {
        cout << "\nenter x ! ";
        cin >> x;
        cout << endl;
        LOGS("the largest element less or equal to " + std::to_string(x) +
            " is " + std::to_string(binSearchLe(A, x)));
    }
}

/**
 * \fn binSearchLe
 * \brief binary search returns the x or the largest element less
 *  than x in a sorted vector 
 */
int binSearchLe(vector <int> &A, int x)
{
    int beg(0), end(A.size() - 1), result(-1), mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (A[mid] <= x)
        {
            beg = mid + 1;
            result = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return A[result];
}

/**
 * \fn testCountAbsolute
 * \brief
 */
void Tester::testCountAbsolute()
{
    int myA[] = {-23, -4, 5, 6, 7, 5, 23, -7};
    vector<int> A(myA, myA + 8);
    VECTOR(A);
    LOGS("count absolute: " + std::to_string(countAbsolute(A)));
}

/**
 * \fn countAbsolute
 * \brief returns the counter of absolute distinct of a vector
 */
int countAbsolute(vector <int> &A)
{
    int res(0), prev_val;
    //copie vers B
    vector<int> B(A);
    vector<int>::iterator itr;
    for(itr = B.begin(); itr != B.end(); itr++)
    {
        *itr = abs(*itr);
    }
    //sort B
    std::sort(B.begin(), B.end());
    //VECTOR(B);
    //passe sur B a chaque changement, B++
    for (itr = B.begin(); itr != B.end(); itr++)
    {
        //LOGS(std::to_string(*itr));
        if (itr == B.begin())
        {
            prev_val = *itr;
            res++;
            continue;
        }
        //not first iteration
        if (prev_val!=*itr)
            res++;
        prev_val = *itr;
    }

    return res; 
}

/**
 * \fn testBinaryGap
 */
void Tester::testBinaryGap()
{
    int N;
    while (1)
    {
        cout <<" enter int !";
        cin >> N;
        binaryBitsLoop(N);
        LOGS("\nbinary gap is " + std::to_string(solutionBinaryGap(N)));
        //binaryBitsLoop(N);
    }
}

/**
 * \fn binaryInt
 * \brief loop over the bits of an int  Note: le resultat est a l'envert.
 *        ex:
 *        4 >>>> 001 et nos 100
 */
void binaryBitsLoop(int N)
{
    unsigned long long x = static_cast<unsigned long long>(N);
    while (x != 0)
    {
        //unsigned long long bit = x & 1;
        if(x & 1 )
        {
            cout << "1";
        }
        else //zero
        {
            cout <<"0";
        }
        x >>= 1;
    }
    cout <<endl;
}
/**
 * \fn solutionBinaryGap
 * \brief count the 0 between to 1 in the binary representation of a int
 */
int solutionBinaryGap(int N)
{
    int res(0), tmp_count(0), flagCount(0);
    //loop over the bits
    unsigned long long x = static_cast<unsigned long long>(N);
    while (x != 0)
    {
        unsigned long long bit = x & 1;
        if( bit == 1 )
        {
            flagCount = 1;
            if (tmp_count > res)
                res = tmp_count;
            tmp_count = 0;
        }
        else //zero
        {
            if (flagCount)
                tmp_count++;
        }
        x >>= 1;
    }
    return res;
}

/**
 * \fn testCyclicRotation
 */
void Tester::testCyclicRotation()
{
    int myA[] = {0, 1, 2,3 ,4,5,6,7,8,9};
    int K;
    vector <int> A (myA, myA + 10);
    VECTOR(A);
    while (1)
    {
        cout << "enter K:  ";
        cin >> K;
        cout <<endl;
        VECTOR(solutionCyclicRotation(A, K));
    }
}

/**
 * \fn solutionCyclicRotation
 */
vector<int> solutionCyclicRotation(vector<int> &A, int K)
{
    size_t i, j, sizeA(A.size());
    vector<int> B(A.size(), 0);
    for (i = 0; i < sizeA; i++)
    {
        j = i + K;
        if (j >= sizeA)
            j = (i + K) % sizeA;
        B[j] = A[i];
    }
    return B;
}

/**
 * \fn testTapeEquilibriumLesson3
 */
void Tester::testTapeEquilibriumLesson3()
{
    int myA[] = {-3, -4, 0, -2};
    vector <int> A (myA, myA + 4);
    LOGS("input:");
    VECTOR(A);
    LOGS(" res tape equilibrium: " + 
            std::to_string(solutionTapeEquilibriumLesson3(A)));
}

/**
 * \fn solutionTapeEquilibriumLesson3
 * \brief calcule la difference minimale entre 2 la somme de partie 
 *        d'un vector
 */
int solutionTapeEquilibriumLesson3(vector<int> &A)
{
    int diff, diffTmp, i, sizeA(A.size()), sumR(0), sumL(A[0]);

    if (sizeA == 2)
        return abs(A[0] - A[1]);
    // travailler avec somme de droite et de gauhe
    for(i = 1; i < sizeA; i++)
    {
        sumR+=A[i];
    }
    //LOGS(std::to_string(sumL));
    //LOGS(std::to_string(sumR));
    diff = abs(sumL-sumR);//1er contre 2...N
    for (i = 1; i < sizeA; i ++)
    {
        sumL+=A[i];
        sumR= sumR - A[i];
        diffTmp = abs(sumL - sumR);
        if (diff > diffTmp)
            diff = diffTmp;
    }
    return diff;
}


/**
 * \fn testPermLesson4
 */
void Tester::testPermLesson4()
{
    int myA[] = {1, 1};
    vector <int> A (myA, myA + 2);
    LOGS("input:");
    VECTOR(A);
    LOGS(" res is permutaion: " + 
            std::to_string(solutionPermLesson4(A)));
} 


/**
 * \fn solutionPermLesson4
 * \brief check whether a vector is a permutation
 */
int solutionPermLesson4(vector <int> &A)
{
    vector<int> B(A);
    size_t i;

    if(A.size() == 1 && A[0] != 1)
        return 0;

    std::sort(B.begin(), B.end());
    if (B[0] != 1)
        return 0;
    for (i = 1; i < B.size(); i ++)
    {
        if (B[i] != B[i - 1]+ 1)
            return 0;
    }
    
  //  VECTOR(B);
    return 1;
}

/**
 * \fn testFrogLesson4
 */
void Tester::testFrogLesson4()
{
    int X;
    int myA[] = {1};
    vector <int> A(myA, myA+1);
    VECTOR(A);
    while(1)
    {
        cout << "input X !";
        cin >> X;
        cout<<endl;
        LOGS("solution: " + std::to_string(solutionFrogLesson4(X, A)));
        cout << endl;
    }
}

/**
 * \fn solutionFrogLesson4
 * \brief find the first time where there is a continues til K + 1 in A
 */
int solutionFrogLesson4(int X, vector <int> &A)
{
    size_t i;
    //creer XV 
    vector <int> XV(X, -1);
    //VECTOR(XV);
    for (i = 0; i < A.size(); i ++)
        if(XV[A[i]-1] == -1)
            XV[A[i]-1] = i;
    //VECTOR(XV);
    std::sort(XV.begin(), XV.end());
    if (XV[0] != -1)
        return XV[X-1];
    return -1;
}

/**
 * \fn testCarsLesson5
 */
void Tester::testCarsLesson5()
{
    int myA[]={0, 1, 0, 1, 1};
    vector<int> A(myA, myA + 5);
    VECTOR(A);
    LOGS("pairs : " +to_string(solutionCarsLesson5(A)));
}

/**
 * \fn solutionCarsLesson5(vector<int> &)
 * \brief count num of 1 after 0
 */
int solutionCarsLesson5(vector <int> &A)
{
    size_t i;
    int s(0), p(0);

    for (i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            s++;
        if (A[i] == 1)
            p = p+s;
        if (p>= 1000000000)
            return -1;
    }
    return p;
}

/**
 * \fn testEqu()
 */
void Tester::testEqu()
{
    int myA[] = {-1, 3, -4, 5, 1, -6, 2, 1};
    vector <int> A(myA, myA + 8);
    VECTOR(A);
    LOGS("eq : " + to_string(solutionEqu(A)));
}

/**
 * \fn solutionEqu
 */
int solutionEqu(vector<int> &A)
{
    int sL(0), sR(0);
    size_t i;

    for (i=1; i < A.size() - 1; i++)
    {
        sR += A[i];
    }
    for (i = 1; i < A.size() -1; i++)
    {
        if (sL == sR)
            return i;
        sL += A[i];
        sR = sR - A[i];
    }
    return -1;

    //LOGS("sR = : " + to_string(sR));
}

/**
 * \fn testMaxProduct
 */
void Tester::testMaxProd()
{
    int myA[] = {-1, 3, -4, 5, 1, -6, 2, 1};
    vector <int> A(myA, myA + 8);
    VECTOR(A);
    LOGS("max prod : " + to_string(solutionMaxProd(A)));
}

/**
 * \fn solutionMaxProd(vector<int> &A)
 */
int solutionMaxProd(vector<int> &A)
{
    int S(A.size());
    sort(A.begin(), A.end());
    VECTOR(A);
    return max(A[S-3]*A[S-2]*A[S-1], A[S-1]*A[0]*A[1]);
}

/**
 * \fn test111()
 */
void Tester::test111()
{
    int myA[] = {-1, 1, 3, 3, 3, 2, 1, 0};
    vector<int> A(myA, myA+ 8);
 
    VECTOR(A);
    LOGS("solution 111: " + to_string(solution111(A)));
}

/**
 * \fn solution111
 */
int solution111(vector<int> &A)
{
    size_t i, k;
    size_t sizeA(A.size());
    int res(0), diff;

    if (sizeA == 3)
        return (A[2] -A[1] == A[1] - A[0]);
    for (i = 0; i< sizeA - 3; i++)
    {
        k = 1;
        diff = A[i+1] - A[i];
        while((A[i + k] == A[i] + static_cast<int>(k*diff)) && i + k < sizeA)
        {
            k++;
            continue;
        }
        if (k>= 2)
            res++;
    }

    return res;
}

/**
 * \fn test222()
 */
void Tester::test222()
{
    string E, L;
    E= "10:00";
    L="13:21";
    while (1)
    {
        cout << "entry : ";
        cin >> E;
        cout << endl << "leaving : " ;
        cin >> L;
        cout << endl;
        solution222(E, L);
        cout <<endl;
    }
    //LOGS("solution 222: " + to_string(solution222(E, L)));
}

/**
 * \fn solution222
 */
int solution222(string &E, string &L)
{
    cout << E << "  to  " << L << endl;
    int res(2), diffHour;
    int minute1 = std::stoi(E.substr(0, 2)) * 60  + 
            stoi(E.substr(3,2));
    int minute2 = std::stoi(L.substr(0, 2)) * 60  + 
            stoi(L.substr(3,2));
    int diffMinute = minute2 - minute1; 
    if ((diffHour = diffMinute / 60) > 0) //at least the begining of the first hour
       res += 3;
    
    if (diffHour > 1 )// more than 1 hour
    {
        res += 4 * (diffHour - 1);
    }
    if ((diffMinute % 60)>0)
    {
        if (diffHour==0)
            res +=3;//least than one hour
        else
            res +=4;
    }
    cout << "res: " << res << endl;
    return res; 
}

/**
 * \fn test333()
 */
void Tester::test333()
{
    LOGS("solution 333: " + to_string(solution333(3)));
}

/**
 * \fn solution333
 */
int solution333(int n)
{
    int d[30];
    int l = 0;
    while (n > 0) {
        d[l] = n % 2;
        n /= 2;
        l++;
    }
    for (int i = 0; i < 30; i++)
        cout << d[i];
    return 0;
}

/**
 * \fn testEquilibrium
 */
void Tester::testEquilibrium()
{
    int myA[] = {3, 1, 2, 4, 3};
    vector<int> A(myA, myA+ 4);

    VECTOR(A);
    LOGS("equilibrium min diff between sums: " + 
            to_string(solutionEquilibrium(A)));
}

/**
 * \fn solutionEquilibrium
 */
int solutionEquilibrium(vector<int> &A)
{
    size_t i;
    int diffMin, sumL(A[0]), sumR(0), diffTmp;
    //first sumR
    for (i = 1; i< A.size(); i ++)
        sumR += A[i];

    //calc diff before
    diffMin = abs(sumR -sumL);

    for (i = 1; i < A.size() -1; i++)
    {
        sumL += A[i];
        sumR -= A[i];
        diffTmp = abs(sumL -sumR);
        //LOGS(to_string(i) + " " + to_string(sumL) + " " + to_string(sumR));
        if (diffTmp < diffMin)
            diffMin = diffTmp;
    }

    return diffMin;
}

/**
 *\fn Tester::testTcp()
 *\brief test le server/client tcp selon le flag tcpserverclientflag
 */
void Tester::testTcp()
{
    try
    {
        if (Appli::getInstance()->getInivalue("tcpserverclientflag")
                == "server")
            testTcpServer();
        else
            testTcpClient();
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
/**
 *\fn Tester::testTcpServer()
 *\brief test le server tcp
 */
void Tester::testTcpServer()
{
    TcpServer myTcpSrv(std::stoi(Appli::getInstance()->getInivalue("tcpportserver")));

    cout << "test tcp server - port :  " << myTcpSrv.getPort() << endl;  
    try
    {
        myTcpSrv.startListening();
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
    return; 
}

/**
 *\fn Tester::testTcpclient()
 *\brief test le client tcp
 */
void Tester::testTcpClient()
{
    TcpClient myTcpClient(Appli::getInstance()->getInivalue("tcpserveripaddress"),             std::stoi(Appli::getInstance()->getInivalue("tcpportserver")));

    cout << "test tcp client address : " << myTcpClient.getServerAddress()
        << " - port :  " << myTcpClient.getPort() << endl;
    try
    {
        myTcpClient.uxClient();
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
    return; 
}

/**
 * \fn Tester::testRoundForest()
 * \brief test the roundforest excercise
 */
void Tester::testRoundForest()
{
    bool bMainMachineFlag = Appli::getInstance()->getInivalue
        ("rfmainmachineflag") == "true"? true: false;
    RoundForest rf(Appli::getInstance()->getInivalue("rffile"),
            stoi(Appli::getInstance()->getInivalue("rfnumber")),
            bMainMachineFlag);
    try
    {
        rf.doIt();
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
    return; 
}
        
