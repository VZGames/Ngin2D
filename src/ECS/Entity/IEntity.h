#ifndef IENTITY_H
#define IENTITY_H

#include "ECS/Components/Components.h"
#include "ECS/Entity/Entity.h"

namespace ngin2D {
class IEntity
{
public:
    Entity *data() const
    {
        return ptr_entity;
    }
public:
    virtual void init(){};
    virtual void followTarget(Entity *target = nullptr) = 0;
    virtual void handleKeyEvent() = 0;
    virtual void handleMouseEvent() = 0;

protected:
    Entity *ptr_entity;
};
}
#endif // IENTITY_H
