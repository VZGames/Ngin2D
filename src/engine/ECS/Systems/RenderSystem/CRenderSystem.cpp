#include "CRenderSystem.h"
#include "LoggerDefines.h"
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
    while(it != entities.end())
    {
        // do update for each entity
        MORGAN_DEBUG("do update RENDER for each entity")
        ++it;
    }
    m_mutex.unlock();
}
END_NAMESPACE

