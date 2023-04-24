#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <random>

template<class T>
inline void safeDelete(T *ptr)
{
    if(ptr != nullptr)
    {
        delete ptr;
        ptr = NULL;
    }
}

template<class T>
inline void safeDeleteArray(T *ptr)
{
    delete []ptr;
}

template <class T>
inline void swap ( T& a, T& b )
{
    T c(a); a=b; b=c;
}

template<class T>
inline T min(const T& a, const T& b)
{
    return (a < b)? a:b;
}

template<class T>
inline T max(const T& a, const T& b)
{
    return (a > b)? a:b;
}

template<typename T>
inline std::string numberToStr(T num)
{
    std::ostringstream convert;
    convert << num;
    return convert.str();
}

template<typename ... TArgs >
inline std::string stringer(TArgs&&... args )
{
    std::string result = "";
    ((result += std::forward<TArgs>(args)), ...);
    return result;
}

template<typename T>
inline T randomNum(T from, T to)
{
    std::random_device dev;
    std::default_random_engine eng(dev());
    std::uniform_int_distribution<T> dist(from, to);

    return dist(eng);
}

inline const char* randomStr(int length) {
    std::random_device dev;
    std::default_random_engine eng(dev());
    std::uniform_int_distribution<int> dist('a', 'z');

    char* result = new char[length + 1];
    for (int i = 0; i < length; i++) {
        char c = dist(eng);
        result[i] = c;
    }

    result[length] = '\0';

    return result;
}

#endif // UTILS_H
