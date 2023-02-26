#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "../Defines/Alias.h"
#include "Entity/Entity.h"

namespace nginvz
{
class EntityManager
{
public:
    static EntityManager *instance();
    Entity createEntity();
    void destroyEntity(Entity &entity);


private:
    EntityManager();
    static EntityManager *s_instance;
    EntityID lastEntity = 0;
};
}


#endif // ENTITYMANAGER_H
