#ifndef IOBJECT_H
#define IOBJECT_H

#include "../Defines/StructsDef.h"
#include "../Math/math2D.h"

class IObject
{
public:
    // properties
    Point2D position;
    Size size;

    // behavior
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};

#endif // IOBJECT_H
