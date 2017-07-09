#include "arraystmpl.h"

template <typename T>
ArraysTmpl<T>::ArraysTmpl(void)
{
}

template <typename T>
ArraysTmpl<T>::~ArraysTmpl(void)
{
}

template <typename T>
void ArraysTmpl<T>::push_back(const T& in_element)
{
    T* ptrT = new T(in_element);
    //....bla bla bla ....
}

