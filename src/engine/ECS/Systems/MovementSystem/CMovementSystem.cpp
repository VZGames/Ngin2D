#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "CCamera.h"
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
        auto *position = entity->getComponent<SPositionComponent>();
        auto *motion   = entity->getComponent<SMotionComponent>();
//        auto *camera   = entity->getComponent<SCameraComponent>();
        if(!(position && motion)) return;
        position->update(motion->velocity);

    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




