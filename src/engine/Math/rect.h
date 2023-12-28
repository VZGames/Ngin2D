#ifndef RECT_H
#define RECT_H
#include "vector2D.h"

template<typename T>
struct Rect
{
    Vector2D<T> top_left;
    Vector2D<T> bottom_right;

};
#endif // RECT_H
