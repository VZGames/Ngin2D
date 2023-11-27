#include "CSpawnSystem.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
CSpawnSystem::CSpawnSystem()
{

}

void CSpawnSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CSpawnSystem::update(CEntity *entity, float dt)
{
    UNUSED(entity);
    UNUSED(dt);
}
END_NAMESPACE

