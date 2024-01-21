#include "CMovementSystem.h"
#include <LoggerDefines.h>
#include "CEntity.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "CSceneManager.h"
#include "AScene.h"

using namespace engine;
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CMovementSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt);
    
    const float scale = CCameraSys::instance()->scale();

    auto position = entity->getComponent<SPositionComponent>();
    auto sprite   = entity->getComponent<SSpriteComponent>();
    auto motion   = entity->getComponent<SMotionComponent>();
    auto camera   = entity->getComponent<SCameraComponent>();
    auto box      = entity->getComponent<SBoxComponent>();

    if(!position || !box || !motion) return;

    if(motion->running)
    {
        if(box->shape.collided()) DBG("Entity [%d] collided", entity->id())
        motion->velocity += motion->mtv * motion->speed; // mtv = minimum translate vector ~ direction (velocity = direction * speed)
        position->update(motion->velocity, dt);
    }

    // if(camera)
    // {
    //     float width = 0.0f;
    //     float height = 0.0f;
    //     CCameraSys::instance()->viewport(width, height);

    //     const Vector2D<float> &boundary = CSceneManager::instance()->currentScene()->boundary();

    //     position->x = std::max(0.0f, std::min(position->x, (boundary.x - sprite->frameWidth) * scale));
    //     position->y = std::max(0.0f, std::min(position->y, (boundary.y - sprite->frameHeight) * scale));
    // }

    
    box->update((*position) / scale);

    CBroadPhaseCulling::instance()->insert(entity->id(),
                                           box->shape.center().x,
                                           box->shape.center().y);
}






