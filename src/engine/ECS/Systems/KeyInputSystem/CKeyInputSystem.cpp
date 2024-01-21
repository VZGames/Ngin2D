#include "CKeyInputSystem.h"
#include "CEntity.h"
#include "ComponentDef/SKeyInputComponent.h"

using namespace engine;
CKeyInputSystem::CKeyInputSystem()
{
}

CKeyInputSystem::~CKeyInputSystem()
{
    DBG("Release Instance CKeyInputSystem At address [%p]", this);
}

void CKeyInputSystem::init(CEntity *entity)
{
    UNUSED(entity)
}

void CKeyInputSystem::update(CEntity *entity, float dt)
{
    UNUSED(dt)

    auto *keyInput = entity->getComponent<SKeyInputComponent>();
    if(keyInput)
    {
        keyInput->listen();
    }
}



