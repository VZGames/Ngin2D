#include "CEnemy.h"
#include "Entity/CEntityManager.h"
#include "Component/ComponentDef/SSpriteComponent.h"
#include "Component/ComponentDef/SHealthComponent.h"
#include "Component/ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(GameScript)
CEnemy::CEnemy()
{
    GameNgin::CEntityManager::instance()->createEntity(this);
    this->addComponent<GameNgin::SPositionComponent>(500, 200)
        ->addComponent<GameNgin::SHealthComponent>(100)
        ->addComponent<GameNgin::SSpriteComponent>("Animal", "./Assets/Characters/Free Cow Sprites.png", 48, 48, 0, 0);
}
END_NAMESPACE
