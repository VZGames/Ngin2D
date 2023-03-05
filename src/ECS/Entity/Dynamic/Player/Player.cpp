#include "Player.h"
#include "../../EntityManager.h"
#include "../../../../Event/KeyEvent/KeyEvent.h"
Player *Player::s_instance = nullptr;
Player::Player()
{
    entity  = EntityManager::instance()->createEntity();
    entity->addComponent<PlayerComponent>();
    entity->addComponent<ColliderComponent>();
    entity->addComponent<PositionComponent>(350, 150);
    entity->addComponent<SpriteComponent>("Lover", "./assets/Characters/BasicCharakterSpritesheet.png", 48, 48, 2);
    entity->addComponent<MotionComponent>(Vector2I(), Vector2I());
    entity->addComponent<HealthComponent>(100);
    entity->addComponent<TransformComponent>();
}

Player *Player::instance()
{
    return s_instance = (s_instance == nullptr)? new Player():s_instance;
}

void Player::handleKeyEvent()
{
    bool hasComponent = ComponentManager::instance()->hasComponentType<MotionComponent>(entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity->componentBitset);

    auto motion = entity->getComponent<MotionComponent>();
    auto sprite = entity->getComponent<SpriteComponent>();

    if(hasComponent)
    {
        KeyEvent::instance()->listen();
        motion->velocity = Vector2I(0, 0);

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            motion->velocity.x += 1 * LEFT;
            sprite->row = 2;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            motion->velocity.x += 1 * RIGHT;
            sprite->row = 3;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            motion->velocity.y += 1 * UP;
            sprite->row = 1;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            motion->velocity.y += 1 * DOWN;
            sprite->row = 0;
            sprite->col = 2;
        }
    }
}

void Player::handleMouseEvent()
{

}
