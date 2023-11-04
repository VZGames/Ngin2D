#ifndef AECSYSTEM_H
#define AECSYSTEM_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(GameNgin)
class CEntity;
class AECSystem
{
public:
    virtual void init() {};
    virtual void update(float dt){ UNUSED(dt) };
    virtual void update(std::vector<CEntity*> &entities, float dt) { UNUSED(entities) UNUSED(dt)};
    virtual void render() {};
protected:
    std::mutex m_mutex;
    std::vector<CEntity*> *m_entities;
};
END_NAMESPACE

#endif // AECSYSTEM_H
