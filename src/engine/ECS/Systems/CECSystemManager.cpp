#include "CECSystemManager.h"
#include "AECSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "AScene.h"

BEGIN_NAMESPACE(Ngin)
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
    m_systems.push_back(&m_camera_system);
    m_systems.push_back(&m_keyinput_system);
    m_systems.push_back(&m_collision_system);
    m_systems.push_back(&m_movement_system);
    m_systems.push_back(&m_render_system);

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
        system->update(dt);
    }
}

END_NAMESPACE





