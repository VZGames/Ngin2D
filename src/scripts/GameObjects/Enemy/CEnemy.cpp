#include "CEnemy.h"
#include "Entity/CEntityManager.h"
#include "Component/ComponentDef/SSpriteComponent.h"
#include "Component/ComponentDef/SHealthComponent.h"
#include "Component/ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(Script)
CEnemy::CEnemy()
{
    Ngin::CEntityManager::instance()->createEntity(this);
    this->addComponent<Ngin::SPositionComponent>(300, 200)
        ->addComponent<Ngin::SHealthComponent>(100)
        ->addComponent<Ngin::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
}
END_NAMESPACE
