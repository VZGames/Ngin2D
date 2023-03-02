#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <queue>
#include <vector>
#include "Entity.h"
#include "../../Defines/Defines.h"

namespace ngin2D {
class EntityManager
{
public:
    ~EntityManager();
    static EntityManager *instance();
    Entity *createEntity();
    bool destroyEntity(Entity &entity);

    Entity *getEntityByID(EntityID id);

    const std::vector<Entity> &getEntities() const;

    uint32_t getEntityCount() const;

private:
    EntityManager();
    static EntityManager *s_instance;

    uint32_t entityCount = 0;
    std::queue<EntityID> availableIDs;
    std::vector<Entity> entities;
};
}


#endif // ENTITYMANAGER_H
