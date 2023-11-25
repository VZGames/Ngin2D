#include "CECSystemManager.h"
#include "LoggerDefines.h"
#include "AECSystem.h"

BEGIN_NAMESPACE(engine)
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
    m_systems.push_back(&m_camera_system);
    m_systems.push_back(&m_spawn_system);
    m_systems.push_back(&m_key_input_system);
    m_systems.push_back(&m_movement_system);
    m_systems.push_back(&m_collision_system);
    m_systems.push_back(&m_motion_system);
    m_systems.push_back(&m_render_system);

    for(auto &system: m_systems)
    {
        system->init();
    }
}

void CECSystemManager::update(float dt)
{
    for(auto &system: m_systems)
    {
        system->update(dt);
    }
}

END_NAMESPACE





