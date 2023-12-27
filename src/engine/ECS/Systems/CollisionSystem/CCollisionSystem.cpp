#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SSpriteComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
    :m_pool(2),m_broad_phase_culling(CBroadPhaseCulling::instance())
{
    m_pool.init();
}

CCollisionSystem::~CCollisionSystem()
{
    m_pool.shutdown();
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
        int currentCell = m_broad_phase_culling->hash(box->shape.center().x, box->shape.center().y);
        if(currentCell >= m_broad_phase_culling->cells()) return;

        m_pool.submit(std::bind(&CCollisionSystem::calculateEntityCollision, this, currentCell, motion, box)).get();
        m_pool.submit(std::bind(&CCollisionSystem::calculateMapCollision, this)).get();
    }
}

bool CCollisionSystem::checkCollision(AShape *A, AShape *B, Vector2D<float>& mtv)
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
    bool notPointingInTheSameDirection = Vector2D<float>::dotProduct(A->center() - B->center(), mtv) < 0;
    if (notPointingInTheSameDirection) { mtv = mtv.reverse(); }



    return true;
}


void CCollisionSystem::calculateMapCollision()
{
}


void CCollisionSystem::calculateEntityCollision(int cell, SMotionComponent *motion, SBoxComponent *box)
{
    for (CEntity *other: m_entities)
    {
        if(m_broad_phase_culling->at(cell).find(other->id()) == m_broad_phase_culling->at(cell).end()) continue;
        else
        {
            auto boxB = other->getComponent<SBoxComponent>();
            if(&boxB->shape == &box->shape) continue;
            bool collided = checkCollision(&box->shape, &boxB->shape, motion->mtv);
            box->shape.setCollided(collided);
            boxB->shape.setCollided(collided);

            if(collided)
            {
                return;
            }
        }

    }
}


END_NAMESPACE

