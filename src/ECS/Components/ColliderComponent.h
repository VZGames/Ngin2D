#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <SDL2/SDL.h>
#include "ComponentBase.h"

namespace ngin2D {
struct ColliderComponent: public ComponentBase<ColliderComponent>
{
    ColliderComponent(float w, float h): w(w), h(h){
        collidedX = 0;
        collidedY = 0;
    }
    float x, y;
    float w, h;
    Point2DF centerI;
    bool collidedX, collidedY;
};
}
#endif // COLLIDERCOMPONENT_H
