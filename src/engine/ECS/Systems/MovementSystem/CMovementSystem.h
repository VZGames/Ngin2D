#ifndef CMOVEMENTSYSTEM_H
#define CMOVEMENTSYSTEM_H

#include "CommonDefine.h"
#include "Systems/IECSystem.h"

BEGIN_NAMESPACE(GameNgin)
class CMovementSystem: public IECSystem
{
public:
    CMovementSystem();

//    Implement IECSystem Interfaces
public:
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CMOVEMENTSYSTEM_H
