#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"

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


