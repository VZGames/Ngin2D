#ifndef AACTOR_H
#define AACTOR_H

#include "IObject.h"
#include "../Defines/PhysicsDef.h"
#include "../Math/math2D.h"


class AActor: public IObject
{
    // IObject interface
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

public:
    const char *name;
    const char *texture;
    Size size;
    Point2D position;
    Vector2I direction, scale;
    float gravity, mass, velocity;
};
#endif // AACTOR_H
