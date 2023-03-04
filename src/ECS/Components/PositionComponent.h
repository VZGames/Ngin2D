#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct PositionComponent: public ComponentBase<PositionComponent>
{
    PositionComponent(Point2D pos): pos(pos){}
    Point2D pos;
};
}

#endif // POSITIONCOMPONENT_H
