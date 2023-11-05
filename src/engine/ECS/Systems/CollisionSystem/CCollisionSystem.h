#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(Ngin)
class CCollisionSystem: public AECSystem
{
public:
    CCollisionSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;
};
END_NAMESPACE

#endif // CCOLLISIONSYSTEM_H
