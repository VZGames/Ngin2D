#include "CECSystemManager.h"
#include "AECSystem.h"
#include "LoggerDefines.h"
BEGIN_NAMESPACE(GameNgin)
CECSystemManager *CECSystemManager::s_instance = nullptr;
CECSystemManager::CECSystemManager()
{

}

CECSystemManager *CECSystemManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CECSystemManager(): s_instance;
}

void CECSystemManager::init()
{
    m_systems.push_back(&m_collision_system);
    m_systems.push_back(&m_movement_system);
    m_systems.push_back(&m_render_system);
}

void CECSystemManager::update(std::vector<CEntity *> &entities, float dt)
{
    for(auto &system: m_systems)
    {
        system->update(entities, dt);
    }
}

void CECSystemManager::render()
{
    for(auto &system: m_systems)
    {
        system->render();
    }
}
END_NAMESPACE





