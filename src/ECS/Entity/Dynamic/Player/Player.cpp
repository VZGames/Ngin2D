#include "Player.h"
#include "ECS/Entity/EntityManager.h"
#include "Event/KeyEvent/KeyEvent.h"
#include "Scene/Camera/Camera.h"


Player *Player::s_instance = nullptr;
Player::Player()
{
    ptr_entity = EntityManager::instance()->createEntity();
    ptr_entity->addComponent<PlayerComponent>();
    ptr_entity->addComponent<CameraComponent>();
    ptr_entity->addComponent<ColliderComponent>();
    ptr_entity->addComponent<PositionComponent>(((g_width - 8)/2) / ZOOM_FACTOR, ((g_height - 8)/2) / ZOOM_FACTOR);
    ptr_entity->addComponent<SpawnComponent>(Point2DI(390, 200));
    ptr_entity->addComponent<SpriteComponent>("Lover", PLAYER_MOTION, 16, 16, 2, 200);
    ptr_entity->addComponent<MotionComponent>(3, Vector2LF(), Vector2LF());
    ptr_entity->addComponent<HealthComponent>(100);
    ptr_entity->addComponent<TransformComponent>();
}

Player::~Player()
{
    delete ptr_entity;
    ptr_entity = NULL;
}

Player *Player::instance()
{
    return s_instance = (s_instance == nullptr)? new Player():s_instance;
}

EntityID Player::getID() const
{
    return ptr_entity->id;
}

void Player::handleKeyEvent()
{
    bool hasComponent = ComponentManager::instance()->hasComponentType<PlayerComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpawnComponent>(ptr_entity->componentBitset);

    if(hasComponent)
    {
        auto motion = ptr_entity->getComponent<MotionComponent>();
        auto sprite = ptr_entity->getComponent<SpriteComponent>();
        auto pos    = ptr_entity->getComponent<PositionComponent>();

        sprite->frameCount = 2;
        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            pos->x += (motion->speed * LEFT);
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            pos->x += (motion->speed * RIGHT);
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            pos->y += (motion->speed * UP);
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            pos->y += (motion->speed * DOWN);
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 2;
        }

//        if(pos->x < 0)
//        {
//            pos->x = 0;
//        }

//        if(pos->y < 0)
//        {
//            pos->y = 0;
//        }

//        if(pos->x > (g_width * 2)/(int)ZOOM_FACTOR - 80)
//        {
//            pos->x = (g_width * 2)/(int)ZOOM_FACTOR - 80;
//        }

//        if(pos->y > g_height - 80)
//        {
//            pos->y = g_height - 80;
//        }
        printf("%d %d\n", pos->x, pos->y);

    }
}

void Player::handleMouseEvent()
{

}
