#include "Player.h"
#include "../../EntityManager.h"
#include "../../../../Event/KeyEvent/KeyEvent.h"
#include "../../../../GameMaps/MapParser.h"

Player *Player::s_instance = nullptr;
Player::Player()
{
    entity  = EntityManager::instance()->createEntity();
    entity->addComponent<PlayerComponent>();
    entity->addComponent<CameraComponent>(Size{g_width, g_height});
    entity->addComponent<ColliderComponent>();
    entity->addComponent<PositionComponent>((g_width/2) / ZOOM_FACTOR, (g_height/2) / ZOOM_FACTOR);
    entity->addComponent<SpriteComponent>("Lover", PLAYER_MOTION, 16, 16, 2, 200);
    entity->addComponent<MotionComponent>(1, Vector2LF(), Vector2LF());
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
        auto position = entity->getComponent<PositionComponent>();


        int mapWidth, mapHeight;
        mapWidth  = MapParser::instance()->getMapSize().width;
        mapHeight = MapParser::instance()->getMapSize().height;

        bool released = KeyEvent::instance()->isReleased();
        motion->velocity = Vector2LF(0.0f, 0.0f);

        sprite->frameCount = 2;
        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            motion->velocity.x += motion->speed * LEFT;
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            motion->velocity.x += motion->speed * RIGHT;
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            motion->velocity.y += motion->speed * UP;
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            motion->velocity.y += motion->speed * DOWN;
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 2;
        }

        if(position->x < 0)
            position->x = 0;
        if(position->x > g_width/ZOOM_FACTOR)
            position->x = g_width/ZOOM_FACTOR - sprite->frameWidth * (ZOOM_FACTOR/2);
        if(position->y < 0)
            position->y = 0;
        if(position->y > g_height/ZOOM_FACTOR)
            position->y = g_height/ZOOM_FACTOR - sprite->frameHeight * (ZOOM_FACTOR/2);
    }
}

void Player::handleMouseEvent()
{

}
