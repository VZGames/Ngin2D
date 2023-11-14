#include "CECSystemManager.h"
#include "LoggerDefines.h"
#include "AECSystem.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
CECSystemManager *CECSystemManager::s_instance = nullptr;
CECSystemManager::CECSystemManager()
{

}

CECSystemManager *CECSystemManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CECSystemManager(): s_instance;
}

void CECSystemManager::init(std::vector<CEntity*> &entities)
{
    m_systems.push_back(&m_keyinput_system);
    m_systems.push_back(&m_camera_system);
    m_systems.push_back(&m_movement_system);
    m_systems.push_back(&m_collision_system);
    m_systems.push_back(&m_render_system);
    m_systems.push_back(&m_motion_system);


    m_threadPool = new CThreadPool(static_cast<int>(m_systems.size()));
    m_threadPool->init();

    for(auto &system: m_systems)
    {
        m_threadPool->submit([&](){
            system->init();
        });
    }

    for(CEntity *entity: entities)
    {
        entity->init();
    }
}

void CECSystemManager::update(float dt)
{
    for(auto &system: m_systems)
    {
        m_threadPool->submit([&](){
            system->update(dt);
        });
    }
}

END_NAMESPACE





