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
    auto fn = [dt](CEntity* entity){
        bool hasPosition    = entity->hasComponent<SPositionComponent>();

        if(!hasPosition) return;
        auto *position      = entity->getComponent<SPositionComponent>();
        bool hasCamera      = entity->hasComponent<SCameraComponent>();
        bool hasSprite      = entity->hasComponent<SSpriteComponent>();

        if(hasCamera)
        {
            auto *camera = entity->getComponent<SCameraComponent>();
            auto *sprite = entity->getComponent<SSpriteComponent>();
            Size2D<float> winSize = CNgin::windowSize();
            camera->offset.setX(position->x - (winSize.width/2 - sprite->frameWidth/2));
            camera->offset.setY(position->y - (winSize.height/2 - sprite->frameHeight/2));

            Ngin::CCamera::instance()->update(camera->offset);
        }
        else
        {
            if(!(hasPosition)) return;
            Offset offset = Ngin::CCamera::instance()->offset();
            MORGAN_DEBUG("%f %f", offset.getX(), offset.getY())
            position->x -= offset.getX();
            position->y -= offset.getY();
        }

    };
    CWorld::forEachEntities(fn);
}

void CCameraSystem::render()
{

}
END_NAMESPACE


