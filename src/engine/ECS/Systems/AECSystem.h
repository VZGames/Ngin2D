#ifndef AECSYSTEM_H
#define AECSYSTEM_H

#include "CommonDefine.h"
#include "CWorld.h"

BEGIN_NAMESPACE(engine)
class AECSystem
{
public:
    virtual void init() { };
    virtual void update(float dt){ UNUSED(dt) };
protected:
    std::mutex m_mutex;
};
END_NAMESPACE

#endif // AECSYSTEM_H
