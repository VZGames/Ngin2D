#ifndef CCAMERASYSTEM_H
#define CCAMERASYSTEM_H

#include "CommonDefine.h"
#include "AECSystem.h"

BEGIN_NAMESPACE(Ngin)
class CCameraSystem: public AECSystem
{
public:
    CCameraSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CCAMERASYSTEM_H
