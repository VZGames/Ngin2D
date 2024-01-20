#ifndef SPOSITIONCOMPONENT_H
#define SPOSITIONCOMPONENT_H

#include <CommonDefine.h>
#include "Component/CComponent.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
struct SPositionComponent: public Vector2D<float>, public CComponent
{
    SPositionComponent(float x = 0.0f, float y = 0.0f): Vector2D<float>(x, y), CComponent(__FUNCTION__)
    {
    }

    void update(Vector2D<float> vec, float dt)
    {
        previous = *this;
        *this += (vec * dt);
    }

    Vector2D<float> previous;

};
END_NAMESPACE

#endif // SPOSITIONCOMPONENT_H
