#include "CPlayer.h"
#include "CKeyEvent.h"
#include "Entity/CEntityManager.h"
#include "CNgin.h"

BEGIN_NAMESPACE(Script)
CPlayer::CPlayer()
{
    Ngin::CEntityManager::instance()->createEntity(this);
    this->addComponent<Ngin::SPositionComponent>(200, 200)
        ->addComponent<Ngin::SHealthComponent>(100)
        ->addComponent<Ngin::SSpriteComponent>("Player", "./debug/assets/Characters/BasicCharakterSpritesheet.png", 48, 48, 2, 200)
        ->addComponent<Ngin::SCameraComponent>(this)
        ->addComponent<Ngin::SMotionComponent>(0.6)
        ->addComponent<Ngin::SKeyInputComponent>();
}

void CPlayer::idle()
{
    m_sprite->frameCount = 2;
}

void CPlayer::jump()
{

}

void CPlayer::walk(MOVE_DIRECTION direction)
{
    switch (direction) {
    case MOVE_DIRECTION::MOVE_LEFT:
    {
        m_sprite->col = 2;
        m_sprite->row = 2;
        m_sprite->frameCount = 4;
        m_motion->direction = -1;
        m_motion->velocity = Vector2DF(m_motion->speed * (-5),0);
        m_camera->offset -= Offset(m_motion->velocity.x, 0);
        break;
    }
    case MOVE_DIRECTION::MOVE_RIGHT:
    {
        m_sprite->col = 2;
        m_sprite->row = 3;
        m_sprite->frameCount = 4;
        m_motion->direction = 1;
        m_motion->velocity = Vector2DF(m_motion->speed * 5,0);
        m_camera->offset -= Offset(m_motion->velocity.x, 0);
        break;
    }
    case MOVE_DIRECTION::MOVE_UP:
    {
        m_sprite->col = 2;
        m_sprite->row = 1;
        m_sprite->frameCount = 4;
        m_motion->direction = -1;
        m_motion->velocity = Vector2DF(0, m_motion->speed * (-5));
        m_camera->offset -= Offset(0, m_motion->velocity.y);
        break;
    }
    case MOVE_DIRECTION::MOVE_DOWN:
    {
        m_sprite->col = 2;
        m_sprite->row = 0;
        m_sprite->frameCount = 4;
        m_motion->direction = 1;
        m_motion->velocity = Vector2DF(0, m_motion->speed * 5);
        m_camera->offset += Offset(0, m_motion->velocity.y);
        break;
    }
    default:
        m_motion->velocity.Zeros();
        break;
    }
}

void CPlayer::attach(CTRL_SLOTS slot)
{
    UNUSED(slot)
}

void CPlayer::init()
{
    m_position = this->getComponent<Ngin::SPositionComponent>();
    m_motion   = this->getComponent<Ngin::SMotionComponent>();
    m_camera   = this->getComponent<Ngin::SCameraComponent>();
    m_sprite   = this->getComponent<Ngin::SSpriteComponent>();
    m_health   = this->getComponent<Ngin::SHealthComponent>();
}

void CPlayer::process(float dt)
{
    UNUSED(dt)

}

void CPlayer::handleKeyInput()
{
    m_motion->velocity.Zeros();

    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
    {
        walk(MOVE_DIRECTION::MOVE_LEFT);
    }
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
    {
        walk(MOVE_DIRECTION::MOVE_RIGHT);
    }
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
    {
        walk(MOVE_DIRECTION::MOVE_UP);
    }
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
    {
        walk(MOVE_DIRECTION::MOVE_DOWN);
    }
}
END_NAMESPACE





