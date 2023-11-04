#include "CMovementSystem.h"
#include "LoggerDefines.h"

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
    while(it != entities.end())
    {
        // do update for each entity
        MORGAN_DEBUG("do update MOVEMENT for each entity")
        ++it;
    }
    m_mutex.unlock();
}
END_NAMESPACE

