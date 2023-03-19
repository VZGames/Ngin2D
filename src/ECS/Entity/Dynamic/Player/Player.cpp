#include "Player.h"
#include "../../EntityManager.h"
#include "../../../../Event/KeyEvent/KeyEvent.h"
#include "../../../../GameMaps/MapParser.h"

Player *Player::s_instance = nullptr;
Player::Player()
{
    entity  = EntityManager::instance()->createEntity();
    entity->addComponent<PlayerComponent>();
    entity->addComponent<CameraComponent>(Size{100, 100});
    entity->addComponent<ColliderComponent>();
    entity->addComponent<PositionComponent>(((g_width - 8)/2) / ZOOM_FACTOR, ((g_height - 8)/2) / ZOOM_FACTOR);
    entity->addComponent<SpriteComponent>("Lover", PLAYER_MOTION, 16, 16, 2, 200);
    entity->addComponent<MotionComponent>(2.5, Vector2LF(), Vector2LF());
    entity->addComponent<HealthComponent>(100);
    entity->addComponent<SpawnComponent>(Point2DI(350, 150));
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
    hasComponent &= ComponentManager::instance()->hasComponentType<CameraComponent>(entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpawnComponent>(entity->componentBitset);

    if(hasComponent)
    {
        auto motion = entity->getComponent<MotionComponent>();
        auto sprite = entity->getComponent<SpriteComponent>();
        auto position = entity->getComponent<PositionComponent>();
        auto camera = entity->getComponent<CameraComponent>();
        auto spawn = entity->getComponent<SpawnComponent>();



        int mapWidth, mapHeight;
        mapWidth  = MapParser::instance()->getMapSize().width;
        mapHeight = MapParser::instance()->getMapSize().height;

        int _x = camera->position.getX();
        int _y = camera->position.getY();

        sprite->frameCount = 2;
        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            _x += motion->speed * LEFT;
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            _x += motion->speed * RIGHT;
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            _y += motion->speed * UP;
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 2;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            _y += motion->speed * DOWN;
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 2;
        }

        camera->position += Point2DI(_x, _y);
        std::cout << camera->position;
    }
}

void Player::handleMouseEvent()
{

}
