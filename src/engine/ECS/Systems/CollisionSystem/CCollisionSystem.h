#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"
#include "AShape.h"
#include "DataStructs/Grid/CGrid.h"
#include "CBroadPhaseCulling.h"

BEGIN_NAMESPACE(engine)
class CCollisionSystem: public AECSystem
{
private:
    std::vector<CEntity*> m_entities;
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
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};
END_NAMESPACE

#endif // CCOLLISIONSYSTEM_H
