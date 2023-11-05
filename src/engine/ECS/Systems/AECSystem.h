#ifndef AECSYSTEM_H
#define AECSYSTEM_H

#include "CommonDefine.h"
#include "CWorld.h"

BEGIN_NAMESPACE(Ngin)
class AECSystem
{
public:
    virtual void init() { };
    virtual void update(float dt){ UNUSED(dt) };
    virtual void render() {};
protected:
    std::mutex m_mutex;
};
END_NAMESPACE

#endif // AECSYSTEM_H
