#include "CPlayer.h"
#include "CKeyEvent.h"
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
    m_x = 200;
    m_y = 200;
    m_speed = 0.6;
    Ngin::CEntityManager::instance()->createEntity(this);
    this->addComponent<Ngin::SPositionComponent>(m_x, m_y)
        ->addComponent<Ngin::SHealthComponent>(100)
        ->addComponent<Ngin::SSpriteComponent>("Player", "./debug/assets/Characters/BasicCharakterSpritesheet.png", 48, 48, 2, 200)
        ->addComponent<Ngin::SCameraComponent>()
        ->addComponent<Ngin::SMotionComponent>(m_speed)
        ->addComponent<Ngin::SKeyInputComponent>();

//    key input map
    Ngin::CKeyEvent::instance()
        ->registerEvent(SDL_SCANCODE_A, std::bind(&CPlayer::walk, this, MOVE_DIRECTION::MOVE_LEFT))
        ->registerEvent(SDL_SCANCODE_D, std::bind(&CPlayer::walk, this, MOVE_DIRECTION::MOVE_RIGHT))
        ->registerEvent(SDL_SCANCODE_W, std::bind(&CPlayer::walk, this, MOVE_DIRECTION::MOVE_UP))
        ->registerEvent(SDL_SCANCODE_S, std::bind(&CPlayer::walk, this, MOVE_DIRECTION::MOVE_DOWN));
}

void CPlayer::idle()
{

}

void CPlayer::jump()
{

}

void CPlayer::walk(MOVE_DIRECTION direction)
{
    switch (direction) {
    case MOVE_DIRECTION::MOVE_LEFT:
        m_x -= m_speed * 5;
        break;
    case MOVE_DIRECTION::MOVE_RIGHT:
        m_x += m_speed * 5;
        break;
    case MOVE_DIRECTION::MOVE_UP:
        m_y -= m_speed * 5;
        break;
    case MOVE_DIRECTION::MOVE_DOWN:
        m_y += m_speed * 5;
        break;
    default:
        break;
    }
}

void CPlayer::attach(CTRL_SLOTS slot)
{
    UNUSED(slot)
}

void CPlayer::handleKeyInput()
{

}
END_NAMESPACE


