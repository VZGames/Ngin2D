#include "CMotionSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"

BEGIN_NAMESPACE(engine)
CMotionSystem::CMotionSystem()
{

}

void CMotionSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CMotionSystem::update(CEntity *entity, float dt)
{
    UNUSED(entity)
    UNUSED(dt)
}
END_NAMESPACE
