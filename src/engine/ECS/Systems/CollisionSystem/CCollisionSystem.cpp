#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SMotionComponent.h"

using namespace engine;
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

        for (CEntity *other: m_entities)
        {
            if(m_broad_phase_culling->at(currentCell).find(other->id()) == m_broad_phase_culling->at(currentCell).end()) continue;
            else
            {
                auto boxB = other->getComponent<SBoxComponent>();
                if(&boxB->shape == &box->shape) continue;
                bool collided = AShape::checkCollision(&box->shape, &boxB->shape, motion->mtv);
                box->shape.setCollided(collided);
                boxB->shape.setCollided(collided);

                if(collided)
                {
                    return;
                }
            }

        }
    }
}




