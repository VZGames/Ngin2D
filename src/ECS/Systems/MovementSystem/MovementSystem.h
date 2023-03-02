#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "../ISystem.h"

namespace ngin2D {
class MovementSystem: public ISystem
{
public:
    MovementSystem();
    // ISystem interface
public:
    virtual void update(float dt) override;
};

}

#endif // MOVEMENTSYSTEM_H
