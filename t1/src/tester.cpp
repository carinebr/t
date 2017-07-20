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

using namespace std;

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
vector<int> solutionCountSemiPrimesLesson11(int N, vector<int> &P, vector<int>&Q);
vector<int> factorizationArray(int n);
vector<int> factorization(int x, vector<int>F);
int gcd(int a, int b, int res);//grand commun diviseur a utiliser quand res == 1

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
    vector<int> v;
//    v.push_back(8);
//    v.push_back(8);
//    v.push_back(4);
//    v.push_back(444);
//    v.push_back(5);
//    v.push_back(4);
//    v.push_back(5);
//    v.push_back(6);
//    v.push_back(6);
//    v.push_back(7);
//    v.push_back(444);
//    v.push_back(789);
//    v.push_back(789);
    v.push_back(9);
    v.push_back(3);
    v.push_back(9);
    v.push_back(3);
    v.push_back(9);
    v.push_back(7);
    v.push_back(9);
    solutionTestOddOccurencesInArrays(v);
    //8 4 8 5 4 5 6 6 7
}
/**
 * \fn solutionTestOddOccurencesInArrays
 * \brief solution of testOddOccurencesInArrays
 * \param[in] vector<int> &A
 */
int solutionTestOddOccurencesInArrays(vector<int> &A)
{
//#define LOGS(STR) 
    for (vector<int>::iterator itr = A.begin(); itr != A.end(); itr++)
    {
        LOGS(std::to_string(*itr));
    }
    bool removed(false);
    LOGS("");
    for (vector<int>::iterator itr = A.begin(); itr != A.end(); itr++)
    {
        removed = false;
        LOGS("*itr:" + std::to_string(*itr));
        vector<int>::iterator itr2=itr;
        itr2++;
        for ( ;itr2 != A.end(); itr2++)
        {
            if (*itr == *itr2)
            {
                LOGS("erase itr2: " + std::to_string(*itr2));
                LOGS("erase itr: " + std::to_string(*itr));
                A.erase(itr2);
                itr = A.erase(itr);
                removed = true;
                break;
            }
        }
        if (removed)
        {
            itr--;
            continue;
        }
    }
    LOGS("fin!");
    for (vector<int>::iterator itr = A.begin(); itr != A.end(); itr++)
    {
        LOGS("*itr: " + std::to_string(*itr));
    }
    
    return *(A.begin());
}

/**
 * \fn Tester::testPermMissingElemLessons3
 * \brief test lessons 3 codility.com
 */
void Tester::testPermMissingElemLessons3()
{
    vector<int> A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
    A.push_back(6);
    A.push_back(7);
    A.push_back(9);
    A.push_back(10);
    A.push_back(5);
    solutionPermMissingElemLessons3(A);
    A.clear();
    A.push_back(1);
    solutionPermMissingElemLessons3(A);
}

/**
 * \fn solutionPermMissingElemLessons3
 * \brief codility lessons 3
 * \param[in] const vectoor<int> A
 * \return the missing element
 */
int solutionPermMissingElemLessons3(vector<int> &A)
{
    int max(A.size() + 1);
    bool found(false);
//#define LOGS(STR) 
    vector<int>::iterator itr, itr2;
    if (A.size() == 1)
        return 2;
    for (itr = A.begin(); itr != A.end(); itr++)
    {
        LOGS(std::to_string(*itr));
    }
    
    for (itr = A.begin(); itr != A.end(); itr++)
    {
        LOGS("*itr: " + std::to_string(*itr));
        if(*itr != max)
        {
            found = false;
            for (itr2 = A.begin(); itr2 != A.end(); itr2++)
            {
                if (itr == itr2)
                    continue;
                if (*itr2 == (*itr) + 1)
                {
                    found = true;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        if (found == false)
            break;
    }
    if (found == false)
    {
        LOGS("missing elem: " + std::to_string((*itr) + 1));
        return (*itr) + 1;
    }
    return 0;
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
//#define LOGS(str)
    LOGS("");
    int sum(X), steps(0);
    while (sum<Y)
    {
        steps++;
        sum+=D;
    }
    LOGS("X: " + std::to_string(X) + " Y: " + std::to_string(Y) + " D: "
            + std::to_string(D) + " steps: " + std::to_string(steps));
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

