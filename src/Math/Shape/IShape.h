#ifndef ISHAPE_H
#define ISHAPE_H

#include "Math/point2d.h"

class IShape
{
public:
    virtual bool contain(Point2DI point) = 0;
    virtual double acreage() = 0;
    virtual double perimeter() = 0;

};
#endif // ISHAPE_H
