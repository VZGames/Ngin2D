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
        ->addComponent<Ngin::SCameraComponent>()
        ->addComponent<Ngin::SMotionComponent>(0.6)
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
    m_sprite->frameCount = 2;
}

void CPlayer::jump()
{

}

void CPlayer::walk(MOVE_DIRECTION direction)
{
    switch (direction) {
    case MOVE_DIRECTION::MOVE_LEFT:
        m_camera->offset += Offset((m_motion->speed * 5), 0);
        break;
    case MOVE_DIRECTION::MOVE_RIGHT:
        m_camera->offset -= Offset((m_motion->speed * 5), 0);
        break;
    case MOVE_DIRECTION::MOVE_UP:
        m_camera->offset -= Offset(0, (m_motion->speed * 5));
        break;
    case MOVE_DIRECTION::MOVE_DOWN:
        m_camera->offset += Offset(0, (m_motion->speed * 5));
        break;
    default:
        break;
    }
}

void CPlayer::attach(CTRL_SLOTS slot)
{
    UNUSED(slot)
}

void CPlayer::motionUpdate(float dt)
{
    UNUSED(dt)
    m_position = this->getComponent<Ngin::SPositionComponent>();
    m_motion   = this->getComponent<Ngin::SMotionComponent>();
    m_camera   = this->getComponent<Ngin::SCameraComponent>();
    m_sprite   = this->getComponent<Ngin::SSpriteComponent>();

    Size2D<float> winSize = Ngin::CNgin::windowSize();
    m_camera->offset.setX(m_position->x - (winSize.width/2));
    m_camera->offset.setY(m_position->y - (winSize.height/2));

    m_position->x -= m_camera->offset.getX();
    m_position->y -= m_camera->offset.getY();
    idle();
}

void CPlayer::handleKeyInput()
{
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
    {
        m_sprite->frameCount = 4;
        m_sprite->col = 2;
        m_sprite->row = 2;
    }
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
    {
        m_sprite->frameCount = 4;
        m_sprite->col = 2;
        m_sprite->row = 3;
    }
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
    {
        m_sprite->frameCount = 4;
        m_sprite->col = 2;
        m_sprite->row = 1;
    }
    if (Ngin::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
    {
        m_sprite->frameCount = 4;
        m_sprite->col = 2;
        m_sprite->row = 0;
    }
}
END_NAMESPACE



