#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

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

#endif // UTILS_H
