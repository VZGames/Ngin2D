#include "CPlayer.h"
#include "CKeyEvent.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(script)
CPlayer::CPlayer()
{
    engine::CEntityManager::instance()->createEntity(this);
    m_position  = this->addComponent<engine::SPositionComponent>(200, 200);
    m_health    = this->addComponent<engine::SHealthComponent>(100);
    m_sprite    = this->addComponent<engine::SSpriteComponent>(__FUNCTION__,
                                                            "./debug/assets/Characters/BasicCharakterSpritesheet.png",
                                                            48,
                                                            48,
                                                            2,
                                                            200);
    m_camera    = this->addComponent<engine::SCameraComponent>(this);
    m_motion    = this->addComponent<engine::SMotionComponent>(0.6);

    m_box       = this->addComponent<engine::SBoxComponent>(E_BODY_TYPE::KINEMATIC, m_position->x, m_position->y);
    m_box->setVertex(Vector2DF(20, 28));
    m_box->setVertex(Vector2DF(28, 28));
    m_box->setVertex(Vector2DF(28, 32));
    m_box->setVertex(Vector2DF(20, 32));
    m_box->setAxes();

    m_keyInput  = this->addComponent<engine::SKeyInputComponent>();
    m_keyInput->registerKey(
        SDL_KEYUP,
        SDL_SCANCODE_E,
        SDL_SCANCODE_SPACE,
        SDL_SCANCODE_A,
        SDL_SCANCODE_D,
        SDL_SCANCODE_W,
        SDL_SCANCODE_S
        );
    
    
    engine::CKeyEvent::instance()->registerKey(SDL_KEYUP, &CPlayer::idle, this);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_E, &CPlayer::attach, this);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_SPACE, &CPlayer::jump, this);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_A, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_LEFT);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_D, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_RIGHT);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_W, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_UP);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_S, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_DOWN);

}

void CPlayer::idle()
{
//    DBG("IDLE")
    m_motion->velocity.Zeros();
    m_motion->running = 0;
    m_sprite->frameCount = 2;
}

void CPlayer::jump()
{
//    DBG("JUMP")
}

void CPlayer::walk(E_MOVE_DIRECTION direction)
{
//    DBG("WALK")
    m_sprite->frameCount = 4;
    m_motion->running = 1;
    if (direction == E_MOVE_DIRECTION::MOVE_LEFT)
    {
        m_sprite->col = 2;
        m_sprite->row = 2;
        m_motion->direction = -1;
        m_motion->velocity.x = m_motion->speed * m_motion->direction * 5;
        m_motion->velocity = Vector2DF(m_motion->speed * (-5),0);
        m_camera->offset -= Offset(m_motion->velocity.x, 0);
    }

    if (direction == E_MOVE_DIRECTION::MOVE_RIGHT)
    {
        m_sprite->col = 2;
        m_sprite->row = 3;
        m_motion->direction = 1;
        m_motion->velocity.x = m_motion->speed * m_motion->direction * 5;
        m_camera->offset -= Offset(m_motion->velocity.x, 0);
    }

    if (direction == E_MOVE_DIRECTION::MOVE_UP)
    {
        m_sprite->col = 2;
        m_sprite->row = 1;
        m_motion->direction = -1;
        m_motion->velocity.y = m_motion->speed * m_motion->direction * 5;
        m_camera->offset -= Offset(0, m_motion->velocity.y);
    }

    if (direction == E_MOVE_DIRECTION::MOVE_DOWN)
    {
        m_sprite->col = 2;
        m_sprite->row = 0;
        m_motion->direction = 1;
        m_motion->velocity.y = m_motion->speed * m_motion->direction * 5;
        m_camera->offset += Offset(0, m_motion->velocity.y);
    }
}

void CPlayer::attach()
{
//    DBG("ATTACK");
}

END_NAMESPACE





