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
    for (int i = 0; i < EntityManager::instance()->getEntityCount(); i++) {
       EntityID id              = EntityManager::instance()->getEntities()[i].id;
       ComponentSet components  = EntityManager::instance()->getEntities()[i].components;
//       printf("EntityID: %d, Components: %s\n", id, components.to_string().c_str());
    }
}

void SystemManager::render()
{

}
}
