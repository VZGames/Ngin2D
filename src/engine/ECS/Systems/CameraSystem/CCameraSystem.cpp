#include "CCameraSystem.h"
#include "CEntity.h"
#include "CCameraSys.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "size2D.h"
#include "CNgin.h"
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
    float scale  = engine::CCameraSys::instance()->scale();

    auto position  = entity->getComponent<SPositionComponent>();
    auto camera    = entity->getComponent<SCameraComponent>();
    auto sprite    = entity->getComponent<SSpriteComponent>();
    if(!(position && sprite)) return;
    if(camera)
    {
        SViewPort* viewport = CCameraSys::instance()->viewport();
        float width  = viewport->width;
        float height = viewport->height;

        viewport->x  = ((position->x + (sprite->frameWidth * scale)) - width/2);
        viewport->y  = ((position->y + (sprite->frameHeight * scale)) - height/2);

        camera->offset.x = position->x - (width/2 - (sprite->frameWidth * scale)/2);
        camera->offset.y = position->y - (height/2 - (sprite->frameHeight * scale)/2);


        CCameraSys::instance()->update();
        CCameraSys::instance()->update(camera->offset);
    }
}

END_NAMESPACE


