#include "CCameraSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "CCameraSys.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "CSceneManager.h"
#include "AScene.h"

BEGIN_NAMESPACE(engine)
CCameraSystem::CCameraSystem()
{

}

void CCameraSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CCameraSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt)
    auto position  = entity->getComponent<SPositionComponent>();
    auto camera    = entity->getComponent<SCameraComponent>();
    auto sprite    = entity->getComponent<SSpriteComponent>();
    if(!(position && sprite)) return;

    // this is stupid code [optimize later]
    if(camera)
    {
        Offset* offset = CCameraSys::instance()->offset();
        const Vector2D<float> &boundary = CSceneManager::instance()->currentScene()->boundary();
        float width = CCameraSys::instance()->viewport()->width;
        float height = CCameraSys::instance()->viewport()->height;


        offset->x = (position->x + (sprite->frameWidth/2) - (width/2)) * dt;
        offset->y = (position->y + (sprite->frameHeight/2) - (height/2)) * dt;

        if(offset->x < 0)
        {
            offset->x = 0;
        }
        else if(offset->x > boundary.x  - width)
        {
            offset->x = boundary.x - width;
        }


        if(offset->y < 0)
        {
            offset->y = 0;
        }
        else if(offset->y > boundary.y - height)
        {
            offset->y = boundary.y - height;
        }



        offset->print("OFFSET");
        boundary.print("BOUNDARY");
        DBG(" boundary.x  - width = %f, boundary.y - height = %f",
            (boundary.x  - width), (boundary.y - height))

    }
}

END_NAMESPACE


