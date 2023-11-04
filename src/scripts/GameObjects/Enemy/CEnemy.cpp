#include "CEnemy.h"
#include "Entity/CEntityManager.h"
#include "Component/ComponentDef/SSpriteComponent.h"
#include "Component/ComponentDef/SHealthComponent.h"
#include "Component/ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(GameScript)
CEnemy::CEnemy()
{
    GameNgin::CEntityManager::instance()->createEntity(this);
    this->addComponent<GameNgin::SPositionComponent>(300, 200)
        ->addComponent<GameNgin::SHealthComponent>(100)
        ->addComponent<GameNgin::SSpriteComponent>("Animal", "./debug/assets/Characters/Cow.png", 32, 32, 3, 200);
}
END_NAMESPACE
