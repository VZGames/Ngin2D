#include "CECSystemManager.h"
#include "IECSystem.h"

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
    std::vector<IECSystem *>::iterator it = m_systems.begin();
    while(it != m_systems.end())
    {
        (*it)->update(entities, dt);
        ++it;
    }
}


END_NAMESPACE




