#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(GameNgin)
CCollisionSystem::CCollisionSystem()
{}

void CCollisionSystem::update(float dt)
{
    UNUSED(dt);
}

void CCollisionSystem::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt);
    m_mutex.lock();
    m_entities = &entities;
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        if(hasPosition)
        {
            MORGAN_DEBUG("Update COLLISION for entity [%d]", entity->id())
        }
    }
    m_mutex.unlock();
}

void CCollisionSystem::render()
{
    m_mutex.lock();
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        if(hasPosition)
        {
        }
    }
    m_mutex.unlock();
}
END_NAMESPACE



