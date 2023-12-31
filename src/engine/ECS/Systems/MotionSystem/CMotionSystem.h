#ifndef CMOTIONSYSTEM_H
#define CMOTIONSYSTEM_H
#include <CommonDefine.h>
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(engine)
class CMotionSystem: public AECSystem
{
public:
    CMotionSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};
END_NAMESPACE

#endif // CMOTIONSYSTEM_H
