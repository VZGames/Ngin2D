#include "CCameraSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "CCameraSys.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SMotionComponent.h"
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
        SViewPort* viewport = CCameraSys::instance()->viewport();
        Offset* offset = CCameraSys::instance()->offset();

        float width  = viewport->width;
        float height = viewport->height;

        offset->x = position->x - (width/2 - (sprite->frameWidth)/2);
        offset->y = position->y - (height/2 - (sprite->frameHeight)/2);
    }
}

END_NAMESPACE


