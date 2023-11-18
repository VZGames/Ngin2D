#include "CMotionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
CMotionSystem::CMotionSystem()
{

}

void CMotionSystem::init()
{
}

void CMotionSystem::update(float dt)
{
    UNUSED(dt)
    // LOCK_GUARD(m_mutex);
    // do update for each entity

    auto fn = [](CEntity* entity){
    };
    CWorld::forEachEntities(fn);
}
END_NAMESPACE
