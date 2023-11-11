#include "CPlayer.h"
#include "CKeyEvent.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(Script)
CPlayer::CPlayer()
{
    float x = 200;
    float y = 200;
    engine::CEntityManager::instance()->createEntity(this);
    this->addComponent<engine::SBodyComponent>(x, y, b2BodyType::b2_kinematicBody)
        ->addComponent<engine::SPositionComponent>(x, y)
        ->addComponent<engine::SHealthComponent>(100)
        ->addComponent<engine::SSpriteComponent>("Player", "./debug/assets/Characters/BasicCharakterSpritesheet.png", 48, 48, 2, 200)
        ->addComponent<engine::SCameraComponent>(this)
        ->addComponent<engine::SMotionComponent>(0.6)
        ->addComponent<engine::SKeyInputComponent>()
        ->addComponent<engine::SBox2DComponent>(
            x,
            y,
            std::vector<b2Vec2>{
                {0,0},
                {48, 0},
                {48, 48},
                {0, 48}
            });
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

    else if (engine::CKeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
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

void CPlayer::init()
{
    m_body     = this->getComponent<engine::SBodyComponent>();
    m_position = this->getComponent<engine::SPositionComponent>();
    m_motion   = this->getComponent<engine::SMotionComponent>();
    m_camera   = this->getComponent<engine::SCameraComponent>();
    m_sprite   = this->getComponent<engine::SSpriteComponent>();
    m_health   = this->getComponent<engine::SHealthComponent>();
    m_box2D    = this->getComponent<engine::SBox2DComponent>();

    m_body->createFixture(&m_box2D->fixtureDef);

}

void CPlayer::process(float dt)
{
    UNUSED(dt)
}

void CPlayer::handleKeyInput()
{
    idle();
    walk();
    jump();
    attach();
}
END_NAMESPACE





