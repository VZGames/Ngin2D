#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CCamera.h"
#include "CEntity.h"
#include "Adapters/Box2DAdapter.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SBodyComponent.h"

BEGIN_NAMESPACE(engine)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::init()
{
    
}

void CMovementSystem::update(float dt)
{
    UNUSED(dt);
    LOCK_GUARD(m_mutex);
    // do update for each entity

    auto fn = [](CEntity* entity){
        auto *position = entity->getComponent<SPositionComponent>();
        auto *motion   = entity->getComponent<SMotionComponent>();
        auto *camera   = entity->getComponent<SCameraComponent>();
        auto *body     = entity->getComponent<SBodyComponent>();
        if(!position || !body) return;
        if(camera && motion)
        {
            position->update(motion->velocity);
            body->SetLinearVelocity(vec2Ftob2Vec2(motion->velocity));
        }
        else
        {
            Offset offset = engine::CCamera::instance()->offset();
            position->x -= offset.getX();
            position->y -= offset.getY();
        }

        body->SetTransform(b2Vec2(position->x, position->y), 0.0f);
    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




