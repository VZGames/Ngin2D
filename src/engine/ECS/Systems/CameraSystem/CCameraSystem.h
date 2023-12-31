#ifndef CCAMERASYSTEM_H
#define CCAMERASYSTEM_H

#include <CommonDefine.h>
#include "AECSystem.h"

BEGIN_NAMESPACE(engine)
class CCameraSystem: public AECSystem
{
public:
    CCameraSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};
END_NAMESPACE

#endif // CCAMERASYSTEM_H
