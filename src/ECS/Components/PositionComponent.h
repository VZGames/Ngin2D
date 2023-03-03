#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct PositionComponent: public ComponentBase<PositionComponent>
{
    PositionComponent(const char *source): source(source){}
    const char *source;
};
}

#endif // POSITIONCOMPONENT_H
