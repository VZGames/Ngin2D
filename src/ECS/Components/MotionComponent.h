#ifndef MotionComponent_H
#define MotionComponent_H

#include "ComponentBase.h"

namespace ngin2D {
struct MotionComponent: public ComponentBase<MotionComponent>
{
    MotionComponent(Vector2I velocity, Vector2I acceleration): velocity(velocity), acceleration(acceleration)
    {}
    int direction = 1; // 1 or -1
    Vector2I velocity;
    Vector2I acceleration;
};
}
#endif // MotionComponent_H
