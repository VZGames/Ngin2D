#include "CSpawnSystem.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
CSpawnSystem::CSpawnSystem()
{

}

void CSpawnSystem::init()
{

}

void CSpawnSystem::update(float dt)
{
    UNUSED(dt);
    // LOCK_GUARD(m_mutex);
    // do update for each entity
    auto fn = [](CEntity* entity){
        UNUSED(entity)
    };
    CWorld::forEachEntities(fn);
}
END_NAMESPACE

