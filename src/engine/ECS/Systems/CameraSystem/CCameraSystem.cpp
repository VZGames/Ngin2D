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

        float width = 0.0f;
        float height = 0.0f;
        CCameraSys::instance()->viewport(width, height);
        float scale = engine::CCameraSys::instance()->scale();


        offset->x = (position->x + (sprite->frameWidth / 2) - (width / 2));
        offset->y = (position->y + (sprite->frameHeight / 2) - (height / 2));

        const Vector2D<float> &boundary = CSceneManager::instance()->currentScene()->boundary();

        offset->x = std::max(0.0f, std::min(offset->x * scale, boundary.x - width)) / scale;
        offset->y = std::max(0.0f, std::min(offset->y * scale, boundary.y - height)) / scale;

        offset->print("OFFSET");
        boundary.print("BOUNDARY");
    }
}

END_NAMESPACE


