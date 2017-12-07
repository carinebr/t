#ifndef D_H_INCLUDED
#define D_H_INCLUDED
/// \file d.h
/// \brief d class header
#include <string>
#include "b.h"
using namespace std;

class D: public B
{
    public :
        //constructor
        D();
        //constructor
        D(int yi);
        //destructor
        ~D(void);

    private:
        int y;
};
#endif  //D_H_INCLUDED
