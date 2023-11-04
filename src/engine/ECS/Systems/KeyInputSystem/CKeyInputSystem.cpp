#include "CKeyInputSystem.h"
#include "CEntity.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(Ngin)
CKeyInputSystem::CKeyInputSystem()
{

}

void CKeyInputSystem::update(std::vector<CEntity*> &entities, float dt)
{
    UNUSED(dt)
    m_entities = &entities;
    // do update for each entity
    for(CEntity *entity: *m_entities)
    {
        bool hasKeyInputComp = entity->hasComponent<SKeyInputComponent>();
        if(!hasKeyInputComp) return;
        entity->handleKeyInput();
    }
}
END_NAMESPACE

