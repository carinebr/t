#ifndef B_H_INCLUDED
#define B_H_INCLUDED
/// \file b.h
/// \brief B class header
#include <string>
using namespace std;

class B
{
    public :
        //constructor 
        B();
        //constructor
        B(int xi);
        //destructor
        virtual ~B(void);//should be virtual!!!
        int getX(){return x;}
        void setX(int in){x = in;}

    protected:
        int xprotected;
    private:
        int x;
};
#endif  //B_H_INCLUDED
