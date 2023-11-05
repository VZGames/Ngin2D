#include "CKeyInputSystem.h"
#include "CEntity.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(Ngin)
CKeyInputSystem::CKeyInputSystem()
{

}

void CKeyInputSystem::init()
{


}

void CKeyInputSystem::update(float dt)
{
    UNUSED(dt)
    // do update for each entity
    auto fn = [dt](CEntity* entity){
        bool hasKeyInputComp = entity->hasComponent<SKeyInputComponent>();
        if(!hasKeyInputComp) return;
        entity->handleKeyInput();

    };
    CWorld::forEachEntities(fn);
}

void CKeyInputSystem::render()
{

}
END_NAMESPACE



