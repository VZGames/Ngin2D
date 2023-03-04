#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include "../ISystem.h"

namespace ngin2D {
class AnimationSystem: public ISystem
{
public:
    AnimationSystem();

    // ISystem interface
public:
    virtual void update(float dt) override;
};
}

#endif // ANIMATIONSYSTEM_H
