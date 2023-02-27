#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <queue>
#include "Entity.h"
#include "../../Defines/Defines.h"

namespace ngin2D {
class EntityManager
{
public:
    static EntityManager *instance();
    Entity createEntity();

private:
    EntityManager();
    static EntityManager *s_instance;

    uint32_t entityCount = 0;
    std::queue<Entity> availableIDs;
};
}


#endif // ENTITYMANAGER_H
