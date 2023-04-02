#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <SDL2/SDL.h>
#include "ComponentBase.h"

namespace ngin2D {
struct ColliderComponent: public ComponentBase<ColliderComponent>
{
    ColliderComponent(float w, float h): w(w), h(h){}
    float x, y;
    float w, h;
};
}
#endif // COLLIDERCOMPONENT_H
