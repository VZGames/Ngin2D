#ifndef CSPAWNSYSTEM_H
#define CSPAWNSYSTEM_H

#include "CommonDefine.h"
#include "AECSystem.h"

BEGIN_NAMESPACE(engine)
class CSpawnSystem: public AECSystem
{
public:
    CSpawnSystem();
    //    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CSPAWNSYSTEM_H