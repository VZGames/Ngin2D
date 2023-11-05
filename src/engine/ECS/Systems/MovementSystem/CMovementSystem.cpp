#include "CMovementSystem.h"
#include "LoggerDefines.h"
#include "CEntity.h"
BEGIN_NAMESPACE(Ngin)
CMovementSystem::CMovementSystem()
{}

void CMovementSystem::init()
{
    
}

void CMovementSystem::update(float dt)
{
    UNUSED(dt);

    // do update for each entity

    auto fn = [](CEntity* entity){
        UNUSED(entity)
    };
    CWorld::forEachEntities(fn);
}

void CMovementSystem::render()
{
    
    // do update for each entity
    auto fn = [](CEntity* entity){
        UNUSED(entity)
    };
    CWorld::forEachEntities(fn);

}
END_NAMESPACE




