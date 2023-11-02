#ifndef SPOSITIONCOMPONENT_H
#define SPOSITIONCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"

BEGIN_NAMESPACE(GameNgin)
struct SPositionComponent: public CComponent
{
    SPositionComponent(float x = 0.0f, float y = 0.0f): x(x), y(y)
    {
        m_name = __FUNCTION__;
    }
    float x, y;
    float lastX, lastY;
};
END_NAMESPACE

#endif // SPOSITIONCOMPONENT_H
