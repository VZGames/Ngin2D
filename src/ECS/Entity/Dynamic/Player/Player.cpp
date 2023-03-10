#include "Player.h"
#include "../../EntityManager.h"
#include "../../../../Event/KeyEvent/KeyEvent.h"

Player *Player::s_instance = nullptr;
Player::Player()
{
    entity  = EntityManager::instance()->createEntity();
    entity->addComponent<PlayerComponent>();
    entity->addComponent<CameraComponent>(Size{200, 200});
    entity->addComponent<ColliderComponent>();
    entity->addComponent<PositionComponent>(0, 0);
    entity->addComponent<SpriteComponent>("Lover", PLAYER_MOTION, 16, 16, 2, 200);
    entity->addComponent<MotionComponent>(Vector2I(), Vector2I());
    entity->addComponent<HealthComponent>(100);
    entity->addComponent<TransformComponent>();
}

Player::~Player()
{
    delete entity;
    entity = NULL;
}

Player *Player::instance()
{
    return s_instance = (s_instance == nullptr)? new Player():s_instance;
}

void Player::handleKeyEvent()
{
    bool hasComponent = ComponentManager::instance()->hasComponentType<PlayerComponent>(entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity->componentBitset);

    if(hasComponent)
    {
        auto motion = entity->getComponent<MotionComponent>();
        auto sprite = entity->getComponent<SpriteComponent>();

        bool released = KeyEvent::instance()->isReleased();
        motion->velocity = Vector2I(0, 0);

        sprite->frameCount = 2;
        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            motion->velocity.x += 1 * LEFT;
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            motion->velocity.x += 1 * RIGHT;
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            motion->velocity.y += 1 * UP;
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            motion->velocity.y += 1 * DOWN;
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 2;
        }
    }
}

void Player::handleMouseEvent()
{

}
