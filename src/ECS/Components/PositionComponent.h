#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct PositionComponent: public ComponentBase<PositionComponent>
{
    PositionComponent(float x = 0.0f, float y = 0.0f): x(x), y(y){}
    float x, y;
    float lastX, lastY;
};
}

#endif // POSITIONCOMPONENT_H
