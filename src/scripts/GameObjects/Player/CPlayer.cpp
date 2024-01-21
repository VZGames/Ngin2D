#include "CPlayer.h"
#include "CKeyEvent.h"
#include "Entity/CEntityManager.h"
#include "Define/Assets/DefineCharacters.h"

using namespace script;
CPlayer::CPlayer()
{
    engine::CEntityManager::instance()->createEntity(this);
    m_position = this->addComponent<engine::SPositionComponent>(320, 244);
    m_health = this->addComponent<engine::SHealthComponent>(100);
    m_sprite = this->addComponent<engine::SSpriteComponent>(__FUNCTION__,
                                                            BASIC_BUNNY,
                                                            48,
                                                            48,
                                                            2,
                                                            200);
    m_sprite->zOrder = 1;

    m_camera = this->addComponent<engine::SCameraComponent>(*m_position);
    m_motion = this->addComponent<engine::SMotionComponent>(100);

    m_box = this->addComponent<engine::SBoxComponent>(E_BODY_TYPE::KINEMATIC, m_position->x, m_position->y);
    m_box->setVertex(20, 28);
    m_box->setVertex(28, 28);
    m_box->setVertex(28, 32);
    m_box->setVertex(20, 32);
    m_box->setAxes();

    m_keyInput = this->addComponent<engine::SKeyInputComponent>();
    m_keyInput->registerKey(
        SDL_KEYUP,
        SDL_SCANCODE_E,
        SDL_SCANCODE_SPACE,
        SDL_SCANCODE_A,
        SDL_SCANCODE_D,
        SDL_SCANCODE_W,
        SDL_SCANCODE_S);

    engine::CKeyEvent::instance()->registerKey(SDL_KEYUP, &CPlayer::idle, this);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_E, &CPlayer::attach, this);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_SPACE, &CPlayer::jump, this);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_A, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_LEFT);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_D, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_RIGHT);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_W, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_UP);
    engine::CKeyEvent::instance()->registerKey(SDL_SCANCODE_S, &CPlayer::walk, this, E_MOVE_DIRECTION::MOVE_DOWN);
}

CPlayer::~CPlayer()
{

}

void CPlayer::idle()
{
    //    DBG("IDLE")
    if (m_motion->running)
    {
        m_motion->velocity.Zeros();
        m_motion->running = 0;
        m_sprite->frameCount = 2;
    }
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
//        DBG("WALK E_MOVE_DIRECTION::MOVE_LEFT")
        m_sprite->col = 2;
        m_sprite->row = 2;
        m_motion->direction = -1;
        m_motion->velocity.x = m_motion->speed * m_motion->direction;
    }

    if (direction == E_MOVE_DIRECTION::MOVE_RIGHT)
    {
//        DBG("WALK E_MOVE_DIRECTION::MOVE_RIGHT")
        m_sprite->col = 2;
        m_sprite->row = 3;
        m_motion->direction = 1;
        m_motion->velocity.x = m_motion->speed * m_motion->direction;
    }

    if (direction == E_MOVE_DIRECTION::MOVE_UP)
    {
//        DBG("WALK E_MOVE_DIRECTION::MOVE_UP")
        m_sprite->col = 2;
        m_sprite->row = 1;
        m_motion->direction = -1;
        m_motion->velocity.y = m_motion->speed * m_motion->direction;
    }

    if (direction == E_MOVE_DIRECTION::MOVE_DOWN)
    {
//        DBG("WALK E_MOVE_DIRECTION::MOVE_DOWN")
        m_sprite->col = 2;
        m_sprite->row = 0;
        m_motion->direction = 1;
        m_motion->velocity.y = m_motion->speed * m_motion->direction;
    }
}

void CPlayer::attach()
{
    //    DBG("ATTACK");
}


