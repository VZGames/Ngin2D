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
    std::vector<CEntity *>::iterator it = entities.begin();
    // do update for each entity
    while(it != entities.end())
    {
        bool hasPosition = (*it)->hasComponent<SPositionComponent>();
        if(hasPosition)
        {
            MORGAN_DEBUG("Update COLLISION for entity [%d]", (*it)->id())
        }
        ++it;
    }
    m_mutex.unlock();
}
END_NAMESPACE


