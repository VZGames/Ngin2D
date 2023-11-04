#ifndef CRENDERSYSTEM_H
#define CRENDERSYSTEM_H

#include "CommonDefine.h"
#include "Systems/AECSystem.h"

BEGIN_NAMESPACE(Ngin)
class CRenderSystem: public AECSystem
{
public:
    CRenderSystem();

    //    Implement IECSystem Interfaces
public:
    virtual void update(float dt) override;
    virtual void update(std::vector<CEntity*> &entities, float dt) override;
    virtual void render() override;

};
END_NAMESPACE

#endif // CRENDERSYSTEM_H
