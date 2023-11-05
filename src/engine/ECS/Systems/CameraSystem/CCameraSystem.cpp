#include "CCameraSystem.h"
#include "CEntity.h"
#include "CCamera.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"

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
        bool hasPosition    = entity->hasComponent<SPositionComponent>();
        bool hasSpriteSheet = entity->hasComponent<SSpriteComponent>();
        bool hasCamera      = entity->hasComponent<SCameraComponent>();
        if(hasCamera)
        {

        }
        else
        {
            if((hasPosition && hasSpriteSheet))
            {
                auto *position = entity->getComponent<Ngin::SPositionComponent>();
                Offset offset = Ngin::CCamera::instance()->offset();
                position->x -= offset.getX();
                position->y -= offset.getY();
            }
            else
            {

            }
        }

    };
    CWorld::forEachEntities(fn);
}

void CCameraSystem::render()
{

}
END_NAMESPACE


