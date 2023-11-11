#ifndef SMOTIONCOMPONENT_H
#define SMOTIONCOMPONENT_H

#include "CommonDefine.h"
#include "Component/CComponent.h"
#include "vector2d.h"

BEGIN_NAMESPACE(engine)
struct SMotionComponent: public CComponent
{
    SMotionComponent(float speed): CComponent(__FUNCTION__), speed(speed)
    {
    }
    float speed;
    int direction;
    Vector2DF velocity;
    Vector2DF acceleration;
    bool running = 0;
};
END_NAMESPACE

#endif // SMOTIONCOMPONENT_H
