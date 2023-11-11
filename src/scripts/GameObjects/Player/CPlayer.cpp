#include "CPlayer.h"
#include "CKeyEvent.h"
#include "Entity/CEntityManager.h"

BEGIN_NAMESPACE(Script)
CPlayer::CPlayer()
{
    engine::CEntityManager::instance()->createEntity(this);
    this->addComponent<engine::SBodyComponent>(b2BodyType::b2_kinematicBody, new b2PolygonShape())
        ->addComponent<engine::SPositionComponent>(200, 200)
        ->addComponent<engine::SHealthComponent>(100)
        ->addComponent<engine::SSpriteComponent>("Player", "./debug/assets/Characters/BasicCharakterSpritesheet.png", 48, 48, 2, 200)
        ->addComponent<engine::SCameraComponent>(this)
        ->addComponent<engine::SMotionComponent>(0.6)
        ->addComponent<engine::SKeyInputComponent>();
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
        MORGAN_DEBUG("JUMP")
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
        MORGAN_DEBUG("ATTACK")
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

    m_body->define.position.Set(m_position->x, m_position->y);

    b2PolygonShape *shape = (b2PolygonShape *)m_body->fixtureDef.shape;
    b2Vec2 vertices[4];
    vertices[0].Set(0,0);
    vertices[1].Set(m_sprite->frameWidth, 0);
    vertices[2].Set(m_sprite->frameWidth, m_sprite->frameHeight);
    vertices[3].Set(0,m_sprite->frameHeight);

    shape->Set(vertices, 4);
    shape->SetAsBox(m_sprite->frameWidth/2, m_sprite->frameHeight/2);
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





