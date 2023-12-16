#ifndef SMOTIONCOMPONENT_H
#define SMOTIONCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
struct SMotionComponent: public CComponent
{
    SMotionComponent(float speed): CComponent(__FUNCTION__), speed(speed)
    {
    }
    float speed;
    int direction;
    Vector2D<float> velocity;
    Vector2D<float> acceleration;
    bool running = 0;
    Vector2D<float> mtv;
};
END_NAMESPACE

#endif // SMOTIONCOMPONENT_H
