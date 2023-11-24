#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CCamera.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SBoxComponent.h"

BEGIN_NAMESPACE(engine)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::init()
{
}

void CMovementSystem::update(float dt)
{
    UNUSED(dt);
    // LOCK_GUARD(m_mutex);
    // do update for each entity

    auto fn = [](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        auto motion   = entity->getComponent<SMotionComponent>();
        auto camera   = entity->getComponent<SCameraComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position) return;
        if(camera && motion)
        {
            position->update(motion->velocity);

        }
        else
        {
            Offset offset = CCamera::instance()->offset();
            position->x -= offset.getX();
            position->y -= offset.getY();
        }

//        DBG("POSITION %f %f", position->x, position->y)
        if(box) box->update(position->x, position->y);

    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




