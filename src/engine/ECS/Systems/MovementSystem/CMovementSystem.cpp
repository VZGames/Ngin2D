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
    float scale = CCameraSys::instance()->scale();

    auto position = entity->getComponent<SPositionComponent>();
    auto motion   = entity->getComponent<SMotionComponent>();
    auto camera   = entity->getComponent<SCameraComponent>();
    auto sprite   = entity->getComponent<SSpriteComponent>();
    auto box      = entity->getComponent<SBoxComponent>();
    if(!position || !box || !motion) return;

    position->x -= offset.x;
    position->y -= offset.y;

    if(camera)
    {
        position->update(motion->velocity);
    }

    if(motion->running)
    {
        position->update(motion->mtv);
    }

    box->update(position);

    const Rect<float> *boundaryLimit = CSceneManager::instance()->currentScene()->boundaryLimit();

    if(position->x < boundaryLimit->top_left.x * scale)
    {
        position->x = boundaryLimit->top_left.x * scale;
    }

    if(position->y < (boundaryLimit->top_left.y * scale))
    {
        position->y = (boundaryLimit->top_left.y * scale);
    }

    if(position->x > (boundaryLimit->bottom_right.x * scale) - sprite->frameWidth)
    {
        position->x = (boundaryLimit->bottom_right.x * scale) - sprite->frameWidth;
    }

    if(position->y > (boundaryLimit->bottom_right.y * scale) - sprite->frameHeight)
    {
        position->y = (boundaryLimit->bottom_right.y * scale) - sprite->frameHeight;
    }

    CBroadPhaseCulling::instance()->insert(entity->id(),
                                           box->shape.center().x,
                                           box->shape.center().y);
}

END_NAMESPACE




