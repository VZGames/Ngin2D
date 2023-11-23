#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"
#include "AShape.h"
#include "ThreadPool/CThreadPool.h"

BEGIN_NAMESPACE(engine)
class CCollisionSystem: public AECSystem
{
private:
    std::vector<AShape*> m_boxes;
    CThreadPool          m_pool;
    bool isCollision(AShape*, AShape*);
public:
    CCollisionSystem();
    ~CCollisionSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CCOLLISIONSYSTEM_H
