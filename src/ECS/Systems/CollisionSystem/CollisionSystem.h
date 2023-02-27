#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../ISystem.h"

namespace ngin2D {
class CollisionSystem: public ISystem
{
public:
    CollisionSystem();

    // ISystem interface
public:
    virtual void update(float dt) override;
};
}

#endif // COLLISIONSYSTEM_H
