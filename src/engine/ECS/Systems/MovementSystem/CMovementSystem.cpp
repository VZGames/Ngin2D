#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "CCamera.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SCameraComponent.h"

BEGIN_NAMESPACE(Ngin)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::update(float dt)
{

}

void CMovementSystem::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt);
    m_entities = &entities;

    
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        entity->motionUpdate(dt);
    }
}

void CMovementSystem::render()
{
    
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        UNUSED(entity)
    }

}
END_NAMESPACE


