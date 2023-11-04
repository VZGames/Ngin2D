#include "CRenderSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"

BEGIN_NAMESPACE(GameNgin)
CRenderSystem::CRenderSystem()
{}

void CRenderSystem::update(float dt)
{
    UNUSED(dt);
}

void CRenderSystem::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt);
    m_mutex.lock();
    std::vector<CEntity *>::iterator it = entities.begin();
    // do update for each entity
    while(it != entities.end())
    {
        MORGAN_DEBUG("Update RENDER for entity [%d]", (*it)->id())
        ++it;
    }
    m_mutex.unlock();
}
END_NAMESPACE

