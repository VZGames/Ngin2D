#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct PositionComponent: public ComponentBase<PositionComponent>
{
    PositionComponent(int x, int y): x(x), y(y){}
    int x, y;
    int lastX, lastY;
};
}

#endif // POSITIONCOMPONENT_H
