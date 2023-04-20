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
    virtual void update(float dt) override;
    virtual void render() override;

    virtual bool hasComponents() override;
    virtual void followTarget(Entity *target) override;

};
}

#endif // SLIME_H
