#include "EntityManager.h"
#include <stdio.h>
#include <algorithm>

namespace ngin2D {
EntityManager *EntityManager::s_instance = nullptr;

EntityManager *EntityManager::instance()
{
    return s_instance = (s_instance == nullptr)? new EntityManager(): s_instance;
}

Entity *EntityManager::createEntity()
{
    EntityID id = availableIDs.front();
    availableIDs.pop();
    entities.push_back(Entity{id});
    entityCount++;
    return &entities.back();
}

bool EntityManager::destroyEntity(Entity &entity)
{
    auto it = std::find(entities.begin(), entities.end(), entity);
    if(it != entities.end())
    {
        entities.erase(it);
        entityCount--;
        return true;
    }
    return false;
}

Entity *EntityManager::getEntityByID(EntityID id)
{
    Entity entity = {id};
    auto it = std::find(entities.begin(), entities.end(), entity);
    if(it != entities.end())
    {
        printf("Entity ID %d, Components: %s\n", it->id, it->components.to_string().c_str());
        return &(*it);
    }

    return nullptr;
}

EntityManager::EntityManager()
{
    for (EntityID i = 0; i < MAX_ENTITIES; i++) {
        availableIDs.push(i);
    }
}

uint32_t EntityManager::getEntityCount() const
{
    return entityCount;
}

const std::vector<Entity> &EntityManager::getEntities() const
{
    return entities;
}
}
