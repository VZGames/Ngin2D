#include "CCameraSystem.h"
#include <LoggerDefines.h>
#include "CEntity.h"
#include "Camera/CCameraSys.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "CSceneManager.h"
#include "AScene.h"

using namespace engine;
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
    auto motion    = entity->getComponent<SMotionComponent>();
    if(!(position && sprite && motion)) return;

    if(camera)
    {
        Offset* offset = CCameraSys::instance()->offset();

        float width = 0.0f;
        float height = 0.0f;
        CCameraSys::instance()->viewport(width, height);
        float scale = engine::CCameraSys::instance()->scale();


        if(!motion->running)
        {
            return;
        }
        else
        {
            float offset_x = (position->x + (sprite->frameWidth * scale) / 2 - (width / 2));
            float offset_y = (position->y + (sprite->frameHeight * scale) / 2 - (height / 2));

            const Vector2D<float> &boundary = CSceneManager::instance()->currentScene()->boundary();

            offset->x = std::max(0.0f, std::min(offset_x, boundary.x - width));
            offset->y = std::max(0.0f, std::min(offset_y, boundary.y - height));

            offset->print("OFFSET");
        }
    }
}




