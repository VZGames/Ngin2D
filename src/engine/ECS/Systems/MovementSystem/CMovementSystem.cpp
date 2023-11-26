#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CCamera.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SBoxComponent.h"

BEGIN_NAMESPACE(engine)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::init()
{
}

void CMovementSystem::update(float dt)
{
    UNUSED(dt);
    Offset offset = CCamera::instance()->offset();

    // do update for each entity
    auto fn = [offset](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        auto motion   = entity->getComponent<SMotionComponent>();
        auto camera   = entity->getComponent<SCameraComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position || !box || !motion) return;

        position->x -= offset.getX();
        position->y -= offset.getY();

        if(camera && motion)
        {
            position->update(motion->velocity);

//            if(box->shape.collided())
//            {
//            }
        }

        position->x += motion->mtv.x;
        position->y += motion->mtv.y;

        box->update(position);
    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




