#ifndef CKEYINPUTSYSTEM_H
#define CKEYINPUTSYSTEM_H


#include "CommonDefine.h"
#include "AECSystem.h"

BEGIN_NAMESPACE(engine)
class CKeyInputSystem: public AECSystem
{
public:
    CKeyInputSystem();
    ~CKeyInputSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init(CEntity *entity) override;
    virtual void update(CEntity *entity, float dt) override;
};
END_NAMESPACE

#endif // CKEYINPUTSYSTEM_H
