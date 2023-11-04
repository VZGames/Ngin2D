#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Ngin)
CCollisionSystem::CCollisionSystem()
{}

void CCollisionSystem::update(float dt)
{
    UNUSED(dt);
}

void CCollisionSystem::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt);
    m_entities = &entities;

    
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        if(hasPosition)
        {
        }
    }
   
}

void CCollisionSystem::render()
{
    
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        UNUSED(entity)
    }
   
}
END_NAMESPACE



