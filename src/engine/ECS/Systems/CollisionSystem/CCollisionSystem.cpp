#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
{
}

CCollisionSystem::~CCollisionSystem()
{
}

void CCollisionSystem::init()
{
    auto fn = [&](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position || !box) return;
        else
        {
            m_boxes.push_back(&box->shape);
        }

    };
    CWorld::forEachEntities(fn);
}

void CCollisionSystem::update(float dt)
{
    UNUSED(dt);

    // do update for each entity
    auto fn = [&](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position || !box) return;
        else
        {
            for (AShape *obj: m_boxes)
            {
                if(obj == &box->shape) continue;
                if(checkCollision(&box->shape, obj))
                {
                    DBG("IS COLLISION")
                }
            }
        }

    };
    CWorld::forEachEntities(fn);
}

bool CCollisionSystem::checkCollision(AShape *A, AShape *B)
{
    for (auto &axis: A->axes()) {
        std::pair<float, float> projectionA = A->projection(axis);
        std::pair<float, float> projectionB = B->projection(axis);

        // Check for overlap
        float overlapLenght = gap(projectionA.first, projectionA.second, projectionB.first, projectionA.second);
        if(overlapLenght == 0.0f)
        {
            return false;
        }
        else
        {
        }
    }

    for (auto &axis: B->axes()) {
        std::pair<float, float> projectionA = B->projection(axis);
        std::pair<float, float> projectionB = A->projection(axis);

        // Check for overlap
        float overlapLenght = gap(projectionA.first, projectionA.second, projectionB.first, projectionA.second);
        if(overlapLenght == 0.0f)
        {
            return false;
        }
        else
        {
        }
    }
    return true;
}

END_NAMESPACE



