#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <iostream>

template<class T>
void safeDelete(T *ptr)
{
    if(ptr != NULL)
    {
        delete ptr;
        ptr = NULL;
    }
}

template<class T>
void safeDeleteArray(T *ptr)
{
    delete []ptr;
}

template <class T>
void swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}

template<class T>
T min(const T& a, const T& b)
{
    return (a < b)? a:b;
}

template<class T>
T max(const T& a, const T& b)
{
    return (a > b)? a:b;
}

#endif // UTILS_H
