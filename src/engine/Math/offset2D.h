#ifndef OFFSET2D_H
#define OFFSET2D_H

#include "vector2D.h"

struct Offset: public Vector2DF
{
    Offset(float x, float y): Vector2DF(x, y){}
};
#endif // OFFSET2D_H
