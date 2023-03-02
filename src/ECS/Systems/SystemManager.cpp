#include "SystemManager.h"
#include "../Entity/EntityManager.h"
#include "../Components/ComponentManager.h"

namespace ngin2D {
SystemManager *SystemManager::s_instance = nullptr;

SystemManager *SystemManager::instance()
{
    return s_instance = (s_instance == nullptr)? new SystemManager():s_instance;
}

void SystemManager::start()
{
    for(auto sys: systems)
    {
        sys.second->update(0.1);
    }
}

SystemManager::SystemManager()
{}
}
