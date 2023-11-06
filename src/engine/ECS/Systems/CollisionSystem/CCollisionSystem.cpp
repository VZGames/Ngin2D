#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Ngin)
CCollisionSystem::CCollisionSystem()
{}

void CCollisionSystem::init()
{


}

void CCollisionSystem::update(float dt)
{
    UNUSED(dt);
    // do update for each entity
    auto fn = [](CEntity* entity){
        bool hasPosition = entity->hasComponent<SPositionComponent>();
        if(!hasPosition) return;

    };
    CWorld::forEachEntities(fn);
}

void CCollisionSystem::render()
{
}
END_NAMESPACE




