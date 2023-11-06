#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"

BEGIN_NAMESPACE(Ngin)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::init()
{
    
}

void CMovementSystem::update(float dt)
{
    UNUSED(dt);

    // do update for each entity

    auto fn = [](CEntity* entity){
        bool hasPosition    = entity->hasComponent<SPositionComponent>();
        bool hasMotion      = entity->hasComponent<SMotionComponent>();

        if(!(hasPosition && hasMotion)) return;
        auto *position = entity->getComponent<SPositionComponent>();
        auto *motion   = entity->getComponent<SMotionComponent>();
        position->update(motion->velocity);
    };
    CWorld::forEachEntities(fn);
}

void CMovementSystem::render()
{
}
END_NAMESPACE




