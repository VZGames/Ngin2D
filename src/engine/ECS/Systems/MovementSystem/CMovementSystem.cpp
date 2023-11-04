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
    m_mutex.lock();
    std::vector<CEntity *>::iterator it = entities.begin();
    // do update for each entity
    while(it != entities.end())
    {
        MORGAN_DEBUG("Update MOVEMENT for entity [%d]", (*it)->id())
        ++it;
    }
    m_mutex.unlock();
}
END_NAMESPACE

