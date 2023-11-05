#include "CEnemy.h"
#include "Entity/CEntityManager.h"
#include "Component/ComponentDef/SSpriteComponent.h"
#include "Component/ComponentDef/SHealthComponent.h"
#include "Component/ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Script)
CEnemy::CEnemy()
{
    Ngin::CEntityManager::instance()->createEntity(this);
    this->addComponent<Ngin::SPositionComponent>(100, 200)
        ->addComponent<Ngin::SHealthComponent>(100)
        ->addComponent<Ngin::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
}

void CEnemy::init()
{
    m_position = this->getComponent<Ngin::SPositionComponent>();
    m_sprite   = this->getComponent<Ngin::SSpriteComponent>();
    m_health   = this->getComponent<Ngin::SHealthComponent>();
}

void CEnemy::process(float dt)
{
    UNUSED(dt)
}
END_NAMESPACE


