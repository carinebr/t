/**
 * \class ArraysTmpl
 *
 * \brief implement  an array template
 *
 */
#include <string>
#include<vector>
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
/**
 * \fn minimum
 * \brief renvoie le + petit de 2 element
 * appel: ex: int a = ., b= ..    minimum<int, int>(a, b);
 * \param[in] arg1, arg2
 * \return le + petit
 */
template <typename Type1, typename Type2>
Type2 minimum(Type1 arg1, Type2 arg2)
{
    if ((Type2) arg1< arg2)
        return (Type2)arg1;
    return arg2;
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


template <typename Type1, typename Type2>
Type2 average2(std::vector<Type1> in_vec)
{
    Type2 ret;
    int taille(in_vec.size());
    typename vector<Type1>::iterator itr;
    Type1 sum(0);

    for (itr = in_vec.begin(); itr != in_vec.end(); itr++)
        sum+=*itr;
    ret = (Type2)sum/(Type2)taille;
    return ret;
}

