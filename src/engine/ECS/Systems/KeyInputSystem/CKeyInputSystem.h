#ifndef CKEYINPUTSYSTEM_H
#define CKEYINPUTSYSTEM_H

#include "CommonDefine.h"
#include "AECSystem.h"

BEGIN_NAMESPACE(Ngin)
class CKeyInputSystem: public AECSystem
{
public:
    CKeyInputSystem();

public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CKEYINPUTSYSTEM_H
