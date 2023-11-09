#ifndef SPOSITIONCOMPONENT_H
#define SPOSITIONCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "vector2d.h"
BEGIN_NAMESPACE(engine)
struct SPositionComponent: public Vector2DF, public CComponent
{
    SPositionComponent(float x = 0.0f, float y = 0.0f): Vector2DF(x, y)
    {
        m_name = __FUNCTION__;
    }

    void update(Vector2DF vec)
    {
        *this += vec;
    }
};
END_NAMESPACE

#endif // SPOSITIONCOMPONENT_H
