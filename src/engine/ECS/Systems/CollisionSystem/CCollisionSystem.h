#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include <CommonDefine.h>
#include "Systems/AECSystem.h"
#include "CBroadPhaseCulling.h"
#include "ThreadPool/CThreadPool.h"

BEGIN_NAMESPACE(engine)
struct SMotionComponent;
struct SBoxComponent;
class CCollisionSystem: public AECSystem
{
private:
    CThreadPool m_pool;
    CBroadPhaseCulling *m_broad_phase_culling;
    std::vector<CEntity*> m_entities;
public:
    CCollisionSystem();
    ~CCollisionSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};
END_NAMESPACE

#endif // CCOLLISIONSYSTEM_H
