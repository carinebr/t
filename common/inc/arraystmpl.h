/**
 * \class ArraysTmpl
 *
 * \brief implement  an array template
 *
 */
#include <string>
using namespace std;
//template <typename Type>
class ArraysTmpl
{
public:
    ArraysTmpl();
 
    virtual ~ArraysTmpl();
 
private:
};

template <typename T>
T aSimpleTmplFunc(T arg1, T arg2)
{
    return arg1;
}

template <typename Type1, typename Type2>
Type2 average(Type1 arg[] , int taille)
{
    int i;
    Type1 sum(0);
    for (i = 0; i < taille; i++)
        sum += arg[i];
    Type2 ret = (Type2)sum/(Type2)i;
    return ret;
}

