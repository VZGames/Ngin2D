#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "CTilemap.h"

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
    auto position = entity->getComponent<SPositionComponent>();
    auto sprite = entity->getComponent<SSpriteComponent>();
    auto motion   = entity->getComponent<SMotionComponent>();
    auto camera      = entity->getComponent<SCameraComponent>();
    auto box      = entity->getComponent<SBoxComponent>();

    if(!position || !box || !motion) return;

    if(motion->running)
    {
        motion->velocity += motion->mtv;
        position->update(motion->velocity, dt);
    }


    if(camera)
    {
        if(position->x < 0)
        {
            position->x = 0;
        }
        if(position->y < 0)
        {
            position->y = 0;
        }
        if(position->x > CTilemap::instance()->coord_limit().x - sprite->frameWidth)
        {
            position->x = CTilemap::instance()->coord_limit().x - sprite->frameWidth;
        }
        if(position->y > CTilemap::instance()->coord_limit().y - sprite->frameHeight)
        {
            position->y = CTilemap::instance()->coord_limit().y - sprite->frameHeight;
        }
    }

    box->update(position);
    CBroadPhaseCulling::instance()->insert(entity->id(),
                                           box->shape.center().x,
                                           box->shape.center().y);
}

END_NAMESPACE




