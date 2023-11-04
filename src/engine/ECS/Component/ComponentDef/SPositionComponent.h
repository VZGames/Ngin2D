#ifndef SPOSITIONCOMPONENT_H
#define SPOSITIONCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "point2D.h"
BEGIN_NAMESPACE(Ngin)
struct SPositionComponent: public CComponent
{
    SPositionComponent(float &x, float &y): x(x), y(y)
    {
        m_name = __FUNCTION__;
    }
    Point2DF toPoint2DF()
    {
        return Point2DF(x, y);
    }
    float &x;
    float &y;
    float lastX, lastY;
};
END_NAMESPACE

#endif // SPOSITIONCOMPONENT_H
