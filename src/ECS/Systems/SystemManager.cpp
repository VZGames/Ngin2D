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
    for(auto sys: systems)
    {
        sys.second->init();
    }
}

void SystemManager::update(float dt)
{
    for(auto sys: systems)
    {
        sys.second->update(dt);
    }
}

void SystemManager::render()
{
    for(auto sys: systems)
    {
        sys.second->render();
    }
}
}
