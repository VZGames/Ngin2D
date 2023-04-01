#ifndef ISHAPE_H
#define ISHAPE_H

#include "Defines/Defines.h"
#include "Math/point2d.h"

class IShape
{  
public:
    virtual Size size() const = 0;
    virtual Point2DI getPosition() const = 0;
    virtual const char *getTypeName() const = 0;
    virtual bool contain(Point2DI point) = 0;
    virtual double acreage() = 0;
    virtual double perimeter() = 0;

};
#endif // ISHAPE_H
