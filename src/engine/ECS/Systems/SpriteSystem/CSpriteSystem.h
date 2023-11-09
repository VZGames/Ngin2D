#ifndef CSPRITESYSTEM_H
#define CSPRITESYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(engine)
class CSpriteSystem: public AECSystem
{
public:
    CSpriteSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void init() override;
    virtual void update(float dt) override;
};
END_NAMESPACE

#endif // CSPRITESYSTEM_H