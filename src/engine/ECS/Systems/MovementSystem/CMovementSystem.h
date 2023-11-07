#ifndef CMOVEMENTSYSTEM_H
#define CMOVEMENTSYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(Ngin)
class CMovementSystem: public AECSystem
{
public:
    CMovementSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CMOVEMENTSYSTEM_H
