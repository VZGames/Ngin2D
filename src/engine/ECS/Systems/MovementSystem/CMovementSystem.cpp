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
        auto *camera   = entity->getComponent<SCameraComponent>();

        if(!(position && motion)) return;
        if(camera)
        {
            position->update(motion->velocity);
        }
        else
        {
            Offset offset = Ngin::CCamera::instance()->offset();
            MORGAN_DEBUG("%f %f", offset.getX(), offset.getY())
            position->x -= offset.getX();
            position->y -= offset.getY();
        }
    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




