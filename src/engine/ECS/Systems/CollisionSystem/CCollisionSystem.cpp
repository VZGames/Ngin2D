#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SMotionComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
    :m_collision_pool(2)
{
    m_collision_pool.init();
}

CCollisionSystem::~CCollisionSystem()
{
    m_collision_pool.shutdown();
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
        auto motion   = entity->getComponent<SMotionComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position || !motion || !box) return;
        else
        {
            for (AShape *obj: m_boxes)
            {
                if(obj == &box->shape) continue;
                if(box->shape.center().distance(obj->center()) > 72) continue;
                bool collided = checkCollision(&box->shape, obj, motion->mtv);
                box->shape.setCollided(collided);
                obj->setCollided(collided);
            }
        }

    };
    CWorld::forEachEntities(fn);
}

bool CCollisionSystem::checkCollision(AShape *A, AShape *B, Vector2DF& mtv)
{
    float minOverlap = std::numeric_limits<float>::infinity();

    for (auto &axis: A->axes()) {
        std::pair<float, float> projectionA = A->projection(axis);
        std::pair<float, float> projectionB = B->projection(axis);

        // Check for overlap
        float overlapLenght = gap(projectionA.first, projectionA.second, projectionB.first, projectionA.second);
        if(overlapLenght == 0.0f)
        {
            mtv.Zeros();
            return false;
        }
        else
        {
            if(overlapLenght < minOverlap)
            {
                minOverlap = overlapLenght;
                mtv = axis * minOverlap;
            }
        }
    }

    for (auto &axis: B->axes()) {
        std::pair<float, float> projectionA = A->projection(axis);
        std::pair<float, float> projectionB = B->projection(axis);

        // Check for overlap
        float overlapLenght = gap(projectionA.first, projectionA.second, projectionB.first, projectionA.second);
        if(overlapLenght == 0.0f)
        {
            mtv.Zeros();
            return false;
        }
        else
        {
            if(overlapLenght < minOverlap)
            {
                minOverlap = overlapLenght;
                mtv = axis * minOverlap;
            }
        }
    }

    // need to reverse MTV if center offset and overlap are not pointing in the same direction
    bool notPointingInTheSameDirection = Vector2DF::dotProduct(A->center() - B->center(), mtv) < 0;
    if (notPointingInTheSameDirection) { mtv = mtv.reverse(); }



    return true;
}

END_NAMESPACE



