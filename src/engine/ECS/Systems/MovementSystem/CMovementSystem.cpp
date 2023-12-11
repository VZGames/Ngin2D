#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CCameraSys.h"
#include "CEntity.h"
#include "CSceneManager.h"
#include "AScene.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "rect.h"


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
    Offset offset = CCameraSys::instance()->offset();
    auto position = entity->getComponent<SPositionComponent>();
    auto motion   = entity->getComponent<SMotionComponent>();
    auto camera   = entity->getComponent<SCameraComponent>();
    auto sprite   = entity->getComponent<SSpriteComponent>();
    auto box      = entity->getComponent<SBoxComponent>();
    if(!position || !box || !motion) return;

    if(camera && motion)
    {
        position->update(motion->velocity);
    }

    if(motion->running)
    {
        position->update(motion->mtv);
    }


    position->x -= offset.x;
    position->y -= offset.y;

    char msg[100];

    sprintf(&msg[0], "Entity %d", entity->id());
    offset.print();
    position->print(msg);

    // if x > window_width/2 - sprite_with/2
    // if x + window_width/2 - sprite_with/2 > window_width
    box->update(position);

    const Rect<float> *boundaryLimit = CSceneManager::instance()->currentScene()->boundaryLimit();

    if(position->x < boundaryLimit->top_left.x)
    {
        position->x = boundaryLimit->top_left.x;
    }
    else if(position->x > boundaryLimit->bottom_right.x - sprite->frameWidth)
    {
        position->x = boundaryLimit->bottom_right.x - sprite->frameWidth;
    }

    if(position->y < boundaryLimit->top_left.x)
    {
        position->y = boundaryLimit->top_left.x;
    }
    else if(position->y > boundaryLimit->bottom_right.y - sprite->frameHeight)
    {
        position->y = boundaryLimit->bottom_right.y - sprite->frameHeight;
    }

    CBroadPhaseCulling::instance()->insert(entity->id(),
                                           box->shape.center().x,
                                           box->shape.center().y);
}

END_NAMESPACE




