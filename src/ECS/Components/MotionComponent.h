#ifndef MotionComponent_H
#define MotionComponent_H

#include "ComponentBase.h"

namespace ngin2D {
struct MotionComponent: public ComponentBase<MotionComponent>
{
    MotionComponent(double speed, Vector2LF velocity, Vector2LF acceleration): speed(speed), velocity(velocity), acceleration(acceleration)
    {}
    double speed;
    Vector2LF velocity;
    Vector2LF acceleration;
};
}
#endif // MotionComponent_H
