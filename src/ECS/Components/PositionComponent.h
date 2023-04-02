#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct PositionComponent: public ComponentBase<PositionComponent>
{
    PositionComponent(float x, float y): x(x), y(y){}
    float x, y;
    float lastX, lastY;
};
}

#endif // POSITIONCOMPONENT_H
