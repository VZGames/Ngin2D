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
    do
    {
        std::vector<std::thread> _threads;
        for(auto &system: m_systems)
        {
            _threads.push_back(std::thread([&](){
                system->update(entities, dt);
            }));
        }

        for(auto &thread:_threads)
        {
            thread.detach();
        }
    }
    while (0);
}


END_NAMESPACE




