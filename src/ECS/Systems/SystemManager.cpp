#include "SystemManager.h"
#include "../Entity/EntityManager.h"
#include "../Components/ComponentManager.h"

namespace ngin2D {
SystemManager *SystemManager::s_instance = nullptr;
SystemManager *SystemManager::instance()
{
    return s_instance = (s_instance == nullptr)? new SystemManager():s_instance;
}

SystemManager::SystemManager()
{}

void SystemManager::init()
{

}

void SystemManager::update(float dt)
{
    for (int i = 0; i < EntityManager::instance()->getEntityCount(); i++)
    {
        const Entity &entity     = EntityManager::instance()->getEntities().at(i);
        EntityID id              = entity.id;
        ComponentSet components  = entity.components;
        for (ComponentID j = 0; j < MAX_COMPONENTS; j++)
        {
            bool bit = components[j]; // 0 or 1
            // ignore bit = 0
            if(!bit)
            {
                continue;
            }
            // printf("EntityID: %d, Components: %d\n", id, j);


        }
    }
}

void SystemManager::render()
{

}
}
