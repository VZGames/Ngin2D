#ifndef MotionComponent_H
#define MotionComponent_H

#include "ComponentBase.h"

namespace ngin2D {
struct MotionComponent: public ComponentBase<MotionComponent>
{
    MotionComponent(float speed): speed(speed)
    {}
    float speed, direction;
    Vector2DF velocity;
    Vector2DF acceleration;
    bool running = 0;
};
}
#endif // MotionComponent_H
