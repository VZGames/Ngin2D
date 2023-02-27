#include "EntityManager.h"
#include "stdio.h"

namespace ngin2D {
EntityManager *EntityManager::s_instance = nullptr;
EntityManager *EntityManager::instance()
{
    return s_instance = (s_instance == nullptr)? new EntityManager(): s_instance;
}

Entity EntityManager::createEntity()
{
    Entity entity = availableIDs.front();
    availableIDs.pop();
    entityCount++;
    return entity;
}

EntityManager::EntityManager()
{
    for (EntityID i = 0; i < MAX_ENTITIES; i++) {
        availableIDs.push(Entity{i});
    }
}

}
