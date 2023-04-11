#ifndef MotionComponent_H
#define MotionComponent_H

#include "ComponentBase.h"

namespace ngin2D {
struct MotionComponent: public ComponentBase<MotionComponent>
{
    MotionComponent(float speed, Vector2DLF velocity, Vector2DLF acceleration): speed(speed), velocity(velocity), acceleration(acceleration)
    {}
    float speed;
    int direction;
    Vector2DLF velocity;
    Vector2DLF acceleration;
};
}
#endif // MotionComponent_H
