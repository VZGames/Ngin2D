#include "EntityManager.h"

EntityManager *EntityManager::s_instance = nullptr;
EntityManager *EntityManager::instance()
{
    return s_instance = (s_instance == nullptr)? new EntityManager():s_instance;
}

EntityManager::EntityManager()
{
    for (int i = 0; i < MAX_ENTITIES; ++i) {

    }
}

