#ifndef OFFSET2D_H
#define OFFSET2D_H

#include "vector2D.h"

struct Offset: public Vector2D<float>
{
    Offset(float x, float y): Vector2D<float>(x, y){}
};
#endif // OFFSET2D_H
