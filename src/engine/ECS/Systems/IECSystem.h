#ifndef IECSYSTEM_H
#define IECSYSTEM_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(GameNgin)
class CEntity;
class IECSystem
{
public:
    virtual void init() {};
    virtual void update(float dt){ UNUSED(dt) };
    virtual void update(std::vector<CEntity*> &entities, float dt) { UNUSED(entities) UNUSED(dt)};
};
END_NAMESPACE

#endif // IECSYSTEM_H
