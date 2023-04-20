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
    EntityID getID() const
    {
        return ptr_entity->id;
    }
public:

    virtual void init(){};
    virtual void update(float dt){};
    virtual void render(){};


    virtual bool hasComponents() = 0;
    virtual void followTarget(Entity *target = nullptr) = 0;
    virtual void handleKeyEvent(){};
    virtual void handleMouseEvent(){};

protected:
    Entity *ptr_entity;
};
}
#endif // IENTITY_H
