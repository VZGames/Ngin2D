#include "CKeyInputSystem.h"
#include "CEntity.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(engine)
CKeyInputSystem::CKeyInputSystem()
{
}

CKeyInputSystem::~CKeyInputSystem()
{

}

void CKeyInputSystem::init()
{

}

void CKeyInputSystem::update(float dt)
{
    UNUSED(dt)
    // LOCK_GUARD(m_mutex);
    // do update for each entity
    auto fn = [](CEntity* entity){
        auto *keyInput = entity->getComponent<SKeyInputComponent>();
        if(keyInput)
        {
            keyInput->listen();
        }
    };
    CWorld::forEachEntities(fn);
}
END_NAMESPACE


