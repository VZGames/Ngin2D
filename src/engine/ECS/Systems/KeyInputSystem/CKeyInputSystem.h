#ifndef CKEYINPUTSYSTEM_H
#define CKEYINPUTSYSTEM_H

#include "CommonDefine.h"
#include "AECSystem.h"

BEGIN_NAMESPACE(Ngin)
class CKeyInputSystem: public AECSystem
{
public:
    CKeyInputSystem();
    virtual void update(std::vector<CEntity*> &, float);
};
END_NAMESPACE

#endif // CKEYINPUTSYSTEM_H
