#include "CECSystemManager.h"
#include <LoggerDefines.h>
#include "AECSystem.h"
#include "CWorld.h"

using namespace engine;
CECSystemManager *CECSystemManager::s_instance = nullptr;
CECSystemManager::CECSystemManager()
{
    m_systems.push_back(&m_spawn_system);
    m_systems.push_back(&m_key_input_system);
    m_systems.push_back(&m_movement_system);
    m_systems.push_back(&m_collision_system);
    m_systems.push_back(&m_camera_system);
    m_systems.push_back(&m_motion_system);
    m_systems.push_back(&m_render_system);
}

CECSystemManager *CECSystemManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CECSystemManager(): s_instance;
}

void CECSystemManager::init(std::vector<CEntity*> &entities)
{
    for(auto &system: m_systems)
    {
        for(CEntity *entity: entities)
        {
            system->init(entity);
        }
    }
}

void CECSystemManager::update(std::vector<CEntity*> &entities, float dt)
{
//    DBG("START_UPDATE")
    for(auto &system: m_systems)
    {
        // do update for each entity
        for(CEntity *entity: entities)
        {
            system->update(entity, dt);
        }
    }
//    DBG("END_UPDATE")
}







