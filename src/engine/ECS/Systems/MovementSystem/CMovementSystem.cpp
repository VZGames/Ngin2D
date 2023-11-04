#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"

BEGIN_NAMESPACE(GameNgin)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::update(float dt)
{

}

void CMovementSystem::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt);
    m_entities = &entities;
    m_mutex.lock();
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        MORGAN_DEBUG("Update MOVEMENT for entity [%d]", entity->id())
    }
    m_mutex.unlock();
}

void CMovementSystem::render()
{
    m_mutex.lock();
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        MORGAN_DEBUG("Render MOVEMENT for entity [%d]", entity->id())
    }
    m_mutex.unlock();
}
END_NAMESPACE


