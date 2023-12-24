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
        float width = 0.0f;
        float height = 0.0f;
        CCameraSys::instance()->viewport(width, height);

        offset->x = (position->x + (sprite->frameWidth/2) - (width/2));
        offset->y = (position->y + (sprite->frameHeight/2) - (height/2));


        offset->x = std::max(0.0f, std::min(offset->x, boundary.x - width));
        offset->y = std::max(0.0f, std::min(offset->y, boundary.y - height));
    }
}

END_NAMESPACE


