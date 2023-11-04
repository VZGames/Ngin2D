#ifndef OFFSET2D_H
#define OFFSET2D_H

#include "point2D.h"

struct Offset: public Point2DF
{
    Offset(float x, float y): Point2DF(x, y){}
    void zero()
    {
        setX(0.0f);
        setY(0.0f);
    }
};
#endif // OFFSET2D_H
