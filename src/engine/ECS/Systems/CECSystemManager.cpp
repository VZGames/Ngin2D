#include "CECSystemManager.h"
#include "AECSystem.h"

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
    std::vector<std::thread> _threads;
    std::vector<AECSystem *>::iterator it = m_systems.begin();
    while(it != m_systems.end())
    {

        _threads.push_back(std::thread([&]{
            (*it)->update(entities, dt);
        }));
        ++it;
    }

    for(auto &thread:_threads)
    {
        thread.detach();
    }
}


END_NAMESPACE




