#include "CPlayer.h"
#include "Entity/CEntityManager.h"
#include "ComponentDef/SSpriteComponent.h"
#include "ComponentDef/SHealthComponent.h"
#include "ComponentDef/SPositionComponent.h"
#include "ComponentDef/SCameraComponent.h"
#include "ComponentDef/SMotionComponent.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(Script)
CPlayer::CPlayer()
{
    Ngin::CEntityManager::instance()->createEntity(this);
    this->addComponent<Ngin::SPositionComponent>(200, 200)
        ->addComponent<Ngin::SHealthComponent>(100)
        ->addComponent<Ngin::SSpriteComponent>("Player", "./debug/assets/Characters/BasicCharakterSpritesheet.png", 48, 48, 2, 200)
        ->addComponent<Ngin::SCameraComponent>()
        ->addComponent<Ngin::SMotionComponent>(1)
        ->addComponent<Ngin::SKeyInputComponent>();
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

