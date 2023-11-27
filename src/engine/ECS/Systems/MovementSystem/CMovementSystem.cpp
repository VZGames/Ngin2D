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

void CMovementSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CMovementSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt);
    Offset offset = CCamera::instance()->offset();
    auto position = entity->getComponent<SPositionComponent>();
    auto motion   = entity->getComponent<SMotionComponent>();
    auto camera   = entity->getComponent<SCameraComponent>();
    auto box      = entity->getComponent<SBoxComponent>();
    if(!position || !box || !motion) return;

    position->x -= offset.x;
    position->y -= offset.y;

    if(camera && motion)
    {
        position->update(motion->velocity);
    }

    if(motion->running)
    {
        position->x += motion->mtv.x;
        position->y += motion->mtv.y;
    }

    box->update(position);
}

END_NAMESPACE




