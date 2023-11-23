#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"
#include "AShape.h"

BEGIN_NAMESPACE(engine)
class CCollisionSystem: public AECSystem
{
private:
    std::vector<AShape*> m_boxes;
    bool checkCollision(AShape*, AShape*);
    bool overlap(float minA, float maxA, float minB, float maxB) {
        return minA <= maxB && maxA >= minB;
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
