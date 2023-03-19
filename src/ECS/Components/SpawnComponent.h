#ifndef SPAWNCOMPONENT_H
#define SPAWNCOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct SpawnComponent: public ComponentBase<SpawnComponent>
{
    SpawnComponent(Point2DI position): position(position){}
    Point2DI position;
};
}


#endif // SPAWNCOMPONENT_H
