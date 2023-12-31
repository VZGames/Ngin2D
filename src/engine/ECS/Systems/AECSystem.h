#ifndef AECSYSTEM_H
#define AECSYSTEM_H

#include <CommonDefine.h>
#include "CWorld.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class AECSystem
{
private:
    CWorld     *m_world(void);

protected:
    std::mutex m_mutex;

public:
    virtual void init(CEntity *entity) = 0;
    virtual void update(CEntity *entity, float dt) = 0;
};
END_NAMESPACE

#endif // AECSYSTEM_H
