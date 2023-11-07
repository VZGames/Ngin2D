#include "CCameraSystem.h"
#include "CEntity.h"
#include "CCamera.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SSpriteComponent.h"
#include "size2D.h"
#include "CNgin.h"
BEGIN_NAMESPACE(Ngin)
CCameraSystem::CCameraSystem()
{

}

void CCameraSystem::init()
{

}

void CCameraSystem::update(float dt)
{
    UNUSED(dt)
    // do update for each entity
    auto fn = [](CEntity* entity){
        auto *position  = entity->getComponent<SPositionComponent>();
        auto *camera    = entity->getComponent<SCameraComponent>();
        auto *sprite    = entity->getComponent<SSpriteComponent>();
        if(!(position && sprite)) return;
        if(camera)
        {

            Size2D<float> winSize = CNgin::windowSize();
            float width  = winSize.width;
            float height = winSize.height;
            float scale  = Ngin::CCamera::instance()->scale();
            camera->offset.setX(position->x - (width/2 - (sprite->frameWidth * scale)/2));
            camera->offset.setY(position->y - (height/2 - (sprite->frameHeight * scale)/2));

            Ngin::CCamera::instance()->update(camera->offset);
        }
    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE


