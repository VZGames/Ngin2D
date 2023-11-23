#include "CCollisionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SBoxComponent.h"

BEGIN_NAMESPACE(engine)
CCollisionSystem::CCollisionSystem()
    :m_pool(2)
{
    m_pool.init();
}

CCollisionSystem::~CCollisionSystem()
{
    m_pool.shutdown();
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
    // LOCK_GUARD(m_mutex);
    // do update for each entity
    auto fn = [&](CEntity* entity){
        auto position = entity->getComponent<SPositionComponent>();
        auto box      = entity->getComponent<SBoxComponent>();
        if(!position || !box) return;
        else
        {
            for (AShape *obj: m_boxes)
            {
                if(isCollision(&box->shape, obj))
                {
                    DBG("IS COLLISION")
                }
            }
        }

    };
    CWorld::forEachEntities(fn);
}

bool CCollisionSystem::isCollision(AShape *A, AShape *B)
{
    int Ok{0};
    m_pool.submit([&](){
              for (Vector2DF &axis: A->axes()) {
                  std::pair<float, float> projectionA = A->projection(axis);
                  std::pair<float, float> projectionB = B->projection(axis);

                  // Check for overlap
                  if (projectionA.first < projectionB.second && projectionA.second > projectionB.first) {
                      Ok *= 1;
                      return;
                  }
                  else
                  {
                      Ok = 0;
                  }
              }
          }).get();

    m_pool.submit([&](){
              for (Vector2DF &axis: B->axes()) {
                  std::pair<float, float> projectionA = A->projection(axis);
                  std::pair<float, float> projectionB = B->projection(axis);

                  // Check for overlap
                  if (projectionA.first < projectionB.second && projectionA.second > projectionB.first) {
                      Ok *= 1;
                      return;
                  }
                  else
                  {
                      Ok = 0;
                  }
              }
          }).get();
    return Ok;
}

END_NAMESPACE



