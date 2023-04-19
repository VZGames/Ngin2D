#ifndef SLIME_H
#define SLIME_H

#include "ECS/Entity/IEntity.h"

namespace ngin2D {
class Slime: public IEntity
{
public:
    Slime();
    ~Slime();

    // IEntity interface
public:
    virtual void init() override;
    virtual void followTarget(Entity *target) override;
    virtual void handleKeyEvent() override;
    virtual void handleMouseEvent() override;
};
}

#endif // SLIME_H
