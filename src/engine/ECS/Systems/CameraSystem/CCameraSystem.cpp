#include "CCameraSystem.h"
#include "CEntity.h"
#include "CCamera.h"
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
    auto fn = [dt](CEntity* entity){
        bool hasPosition    = entity->hasComponent<SPositionComponent>();
        bool hasCamera      = entity->hasComponent<SCameraComponent>();
        if(hasCamera)
        {
            entity->process(dt);
        }
        else
        {
            if(!(hasPosition)) return;
            auto *position = entity->getComponent<SPositionComponent>();
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


