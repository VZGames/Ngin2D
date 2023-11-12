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
    m_systems.emplace_back(&m_keyinput_system);
    m_systems.emplace_back(&m_camera_system);
    m_systems.emplace_back(&m_movement_system);
    m_systems.emplace_back(&m_collision_system);
    m_systems.emplace_back(&m_render_system);
    m_systems.emplace_back(&m_motion_system);

    for(auto &system: m_systems)
    {
        system->init();
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
        std::thread(std::bind(&AECSystem::update, system, dt)).join();
    }
}

END_NAMESPACE





