#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
{}

void CCollisionSystem::init()
{
}

void CCollisionSystem::update(float dt)
{
    UNUSED(dt);
    // LOCK_GUARD(m_mutex);
    // do update for each entity
    auto fn = [](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position || !box) return;
        else
        {
//            std::pair<float, float> projectionA = box->shape.projection(axis);
//            std::pair<float, float> projectionB = box->shape.projection(axis);

//            // Check for overlap
//            if (projectionA.second < projectionB.first || projectionB.second < projectionA.first) {
//                // No overlap on this axis, so shapes are not colliding
//            }
        }

    };
    CWorld::forEachEntities(fn);
}

END_NAMESPACE




