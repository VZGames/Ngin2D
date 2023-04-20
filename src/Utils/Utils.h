#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>


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

template< typename ... Args >
std::string stringer(Args const& ... args )
{
    std::ostringstream stream;
    using List= int[];
    (void)List{0, ( (void)(stream << args), 0 ) ... };

    return stream.str();
}

#endif // UTILS_H
