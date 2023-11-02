#include "CPlayer.h"
#include "Entity/CEntityManager.h"
#include "Component/ComponentDef/SSpriteComponent.h"
#include "Component/ComponentDef/SHealthComponent.h"
#include "Component/ComponentDef/SPositionComponent.h"
#include "Component/ComponentDef/SCameraComponent.h"

BEGIN_NAMESPACE(GameScript)
CPlayer::CPlayer()
{
    GameNgin::CEntityManager::instance()->createEntity(this);
    this->addComponent<GameNgin::SPositionComponent>(0, 0)
        ->addComponent<GameNgin::SHealthComponent>(100)
        ->addComponent<GameNgin::SSpriteComponent>("textureID", "source", 48, 48, 0, 0)
        ->addComponent<GameNgin::SCameraComponent>();
}

void CPlayer::idle()
{

}

void CPlayer::jump()
{

}

void CPlayer::walk(MOVE_DIRECTION direction)
{
    UNUSED(direction)
}

void CPlayer::attach(CTRL_SLOTS slot)
{
    UNUSED(slot)
}
END_NAMESPACE

