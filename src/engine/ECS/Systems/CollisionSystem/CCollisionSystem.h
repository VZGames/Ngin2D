#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "CommonDefine.h"
#include "Systems/IECSystem.h"

BEGIN_NAMESPACE(GameNgin)
class CCollisionSystem: public IECSystem
{
public:
    CCollisionSystem();

//    Implement IECSystem Interfaces
public:
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CCOLLISIONSYSTEM_H
