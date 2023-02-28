#include "EntityManager.h"
#include "stdio.h"

namespace ngin2D {
EntityManager *EntityManager::s_instance = nullptr;
EntityManager::~EntityManager()
{
    delete entities;
    entities = NULL;
}

EntityManager *EntityManager::instance()
{
    return s_instance = (s_instance == nullptr)? new EntityManager(): s_instance;
}

Entity &EntityManager::createEntity()
{
    EntityID id = availableIDs.front();
    entities[id] = Entity{id};
    availableIDs.pop();
    entityCount++;
    return entities[id];
}

bool EntityManager::destroyEntity(Entity &entity)
{
    Entity *_ptr = &entity;
    _ptr = NULL;
    return true;
}

EntityManager::EntityManager()
{
    entities = new Entity[MAX_ENTITIES];

    for (EntityID i = 0; i < MAX_ENTITIES; i++) {
        availableIDs.push(i);
    }
}

uint32_t EntityManager::getEntityCount() const
{
    return entityCount;
}

Entity *EntityManager::getEntities() const
{
    return entities;
}
}
