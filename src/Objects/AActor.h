#ifndef AACTOR_H
#define AACTOR_H

#include "IObject.h"
#include "../Defines/PhysicsDef.h"
#include "../Math/math2D.h"


class AActor: public IObject
{
    // IObject interface
public:
    virtual void draw();
    virtual void update();
    virtual void clean();

public:
    const char *name;
    const char *texture;
    Size size;
    Point2D position, direction;
    float gravity, mass, velocity;
};
#endif // AACTOR_H
