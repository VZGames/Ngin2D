#ifndef MOTIONCOMPONENT_H
#define MOTIONCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct MotionComponent: public ComponentBase<MotionComponent>
{
    MotionComponent(Vector2I velocity, Vector2I acceleration): velocity(velocity), acceleration(acceleration)
    {}
    Vector2I velocity;
    Vector2I acceleration;
};
}
#endif // MOTIONCOMPONENT_H
