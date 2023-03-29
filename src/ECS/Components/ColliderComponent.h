#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <SDL2/SDL.h>
#include "ComponentBase.h"

namespace ngin2D {
struct ColliderComponent: public ComponentBase<ColliderComponent>
{
    int x, y;
    int w, h;
};
}
#endif // COLLIDERCOMPONENT_H
