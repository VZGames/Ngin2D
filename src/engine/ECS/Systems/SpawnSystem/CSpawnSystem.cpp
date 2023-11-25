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
    
    // do update for each entity
    auto fn = [](CEntity* entity){
        UNUSED(entity)
    };
    CWorld::forEachEntities(fn);
}
END_NAMESPACE

