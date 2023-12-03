#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SMotionComponent.h"
//#include "ComponentDef/SSpriteComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
{
}

CCollisionSystem::~CCollisionSystem()
{
}

void CCollisionSystem::init(CEntity *entity)
{
    auto position = entity->getComponent<SPositionComponent>();
    auto box      = entity->getComponent<SBoxComponent>();
    if(!position || !box) return;
    else
    {
        m_entities.push_back(entity);
    }
}

void CCollisionSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt);
    auto position = entity->getComponent<SPositionComponent>();
    auto motion   = entity->getComponent<SMotionComponent>();
    auto box      = entity->getComponent<SBoxComponent>();
    if(!position || !motion || !box) return;
    else
    {
        CBroadPhaseCulling *ins = CBroadPhaseCulling::instance();
        int currentCell = ins->hash(position->x, position->y);
        for (CEntity *other: m_entities)
        {
            if(ins->at(currentCell).find(other->id()) == ins->at(currentCell).end()) continue;
            else
            {
                auto boxB = other->getComponent<SBoxComponent>();
                if(&boxB->shape == &box->shape) continue;
                bool collided = checkCollision(&box->shape, &boxB->shape, motion->mtv);
                box->shape.setCollided(collided);
                boxB->shape.setCollided(collided);

                if(collided)
                {
                    break;
                }
            }

        }
    }
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


