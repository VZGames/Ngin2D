#ifndef MotionComponent_H
#define MotionComponent_H

#include "ComponentBase.h"

namespace ngin2D {
struct MotionComponent: public ComponentBase<MotionComponent>
{
    MotionComponent(float speed, Vector2LF velocity, Vector2LF acceleration): speed(speed), velocity(velocity), acceleration(acceleration)
    {}
    float speed;
    int direction;
    Vector2LF velocity;
    Vector2LF acceleration;
};
}
#endif // MotionComponent_H
