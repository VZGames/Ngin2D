#include "Player.h"
#include "../../EntityManager.h"
#include "../../../../Event/KeyEvent/KeyEvent.h"

Player *Player::s_instance = nullptr;
Player::Player()
{
    std::cout << g_width << std::endl;
    entity  = EntityManager::instance()->createEntity();
    entity->addComponent<PlayerComponent>();
    entity->addComponent<CameraComponent>(Size{g_width/ZOOM_FACTOR, g_height/ZOOM_FACTOR});
    entity->addComponent<ColliderComponent>();
    entity->addComponent<PositionComponent>((g_width - 48 * ZOOM_FACTOR)/(2*ZOOM_FACTOR), (g_height  - 48 * ZOOM_FACTOR)/(2*ZOOM_FACTOR));
    entity->addComponent<SpriteComponent>("Lover", PLAYER_MOTION, 48, 48, 2, 200);
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
            motion->velocity.x += 3 * LEFT;
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            motion->velocity.x += 3 * RIGHT;
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            motion->velocity.y += 3 * UP;
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            motion->velocity.y += 3 * DOWN;
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 2;
        }
    }
}

void Player::handleMouseEvent()
{

}
