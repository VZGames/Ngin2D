#ifndef CMOVEMENTSYSTEM_H
#define CMOVEMENTSYSTEM_H

#include <CommonDefine.h>
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(engine)
class CMovementSystem: public AECSystem
{
public:
    CMovementSystem();

//    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};
END_NAMESPACE

#endif // CMOVEMENTSYSTEM_H
