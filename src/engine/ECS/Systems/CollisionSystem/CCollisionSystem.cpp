#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
{}

void CCollisionSystem::init()
{


}

void CCollisionSystem::update(float dt)
{
    UNUSED(dt);
    LOCK_GUARD(m_mutex);
    // do update for each entity
    auto fn = [](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        if(!position) return;

    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




