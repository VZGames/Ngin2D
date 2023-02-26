#include "EntityManager.h"

namespace nginvz {
EntityManager *EntityManager::s_instance = nullptr;
EntityManager *EntityManager::instance()
{
    return s_instance = (s_instance == nullptr)? new EntityManager():s_instance;
}
EntityManager::EntityManager()
{}

Entity EntityManager::createEntity()
{
    lastEntity++;
    return {lastEntity};
}

void EntityManager::destroyEntity(Entity &entity)
{
}
}

