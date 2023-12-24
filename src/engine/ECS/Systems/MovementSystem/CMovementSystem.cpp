#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "CSceneManager.h"
#include "AScene.h"

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

    const Vector2D<float> &boundary = CSceneManager::instance()->currentScene()->boundary();

    float width = CCameraSys::instance()->viewport()->width;
    float height = CCameraSys::instance()->viewport()->height;

    float boundaryX = (boundary.x > width)
                          ? boundary.x - sprite->frameWidth
                          : width - sprite->frameWidth;
    float boundaryY= (boundary.y > height)
                          ? boundary.y - sprite->frameHeight
                          : height - sprite->frameHeight;
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

        if(position->x > boundaryX)
        {
            position->x = boundaryX;
        }

        if(position->y > boundaryY)
        {
            position->y = boundaryY;
        }


        position->print("POSITION");
        DBG(" boundary.x  - width = %f, boundary.y - height = %f",
            boundaryX, boundaryY)
    }


    box->update(position);
    CBroadPhaseCulling::instance()->insert(entity->id(),
                                           box->shape.center().x,
                                           box->shape.center().y);
}

END_NAMESPACE




