#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "../ISystem.h"

namespace ngin2D {
class MovementSystem: public ISystem
{
public:
    static MovementSystem *instance();
    // ISystem interface
public:
    virtual void update(float dt) override;

private:
    MovementSystem();
    static MovementSystem *s_instance;
};

}

#endif // MOVEMENTSYSTEM_H
