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
    CThreadPool          m_collision_pool;
private:
    bool checkCollision(AShape*, AShape*, Vector2DF&);

    bool overlap(float A0, float A1, float B0, float B1)
    {
        return A0 <= B1 && A1 >= B0;
    }

    float gap(float A0, float A1, float B0, float B1)
    {
        if (!overlap(A0, A1, B0, B1)) { return 0.0f; }
        return std::min(A1, B1) - std::max(A0, B0);
    }

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
