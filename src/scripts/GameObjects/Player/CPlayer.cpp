#include "CPlayer.h"
#include "CKeyEvent.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(script)
CPlayer::CPlayer()
{
    engine::CEntityManager::instance()->createEntity(this);
    m_body      = this->addComponent<engine::SBodyComponent>(b2BodyType::b2_kinematicBody);
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
    m_box2D     = this->addComponent<engine::SBox2DComponent>(
        36,
        24,
        std::vector<b2Vec2>{{16,24},{32, 24},{32, 32},{16, 32}});
}

void CPlayer::idle()
{
    m_motion->velocity.Zeros();
    m_motion->running = 0;
    m_sprite->frameCount = 2;
}

void CPlayer::jump()
{
    if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_SPACE))
    {
        DBG("JUMP")
    }
}

void CPlayer::walk()
{
    if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
    {
        m_sprite->col = 2;
        m_sprite->row = 2;
        m_sprite->frameCount = 4;
        m_motion->running = 1;
        m_motion->direction = -1;
        m_motion->velocity = Vector2DF(m_motion->speed * (-5),0);
        m_camera->offset -= Offset(m_motion->velocity.x, 0);
    }

    if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
    {
        m_sprite->col = 2;
        m_sprite->row = 3;
        m_sprite->frameCount = 4;
        m_motion->running = 1;
        m_motion->direction = 1;
        m_motion->velocity = Vector2DF(m_motion->speed * 5,0);
        m_camera->offset -= Offset(m_motion->velocity.x, 0);
    }

    if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
    {
        m_sprite->col = 2;
        m_sprite->row = 1;
        m_sprite->frameCount = 4;
        m_motion->running = 1;
        m_motion->direction = -1;
        m_motion->velocity = Vector2DF(0, m_motion->speed * (-5));
        m_camera->offset -= Offset(0, m_motion->velocity.y);
    }

    if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
    {
        m_sprite->col = 2;
        m_sprite->row = 0;
        m_sprite->frameCount = 4;
        m_motion->running = 1;
        m_motion->direction = 1;
        m_motion->velocity = Vector2DF(0, m_motion->speed * 5);
        m_camera->offset += Offset(0, m_motion->velocity.y);
    }
}

void CPlayer::attach()
{
    if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_E))
    {
        DBG("ATTACK")
    }
}

END_NAMESPACE





