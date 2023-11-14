#ifndef CMOTIONSYSTEM_H
#define CMOTIONSYSTEM_H
#include "CommonDefine.h"
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(engine)
class CMotionSystem: public AECSystem
{
public:
    CMotionSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CMOTIONSYSTEM_H