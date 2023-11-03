#include "CCollisionSystem.h"
#include "LoggerDefines.h"
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
    std::vector<CEntity *>::iterator it = entities.begin();
    while(it != entities.end())
    {
        // do update for each entity
        MORGAN_DEBUG("do update COLLISION for each entity")
        ++it;
    }
}
END_NAMESPACE


