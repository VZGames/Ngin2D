#include "Player.h"
#include "ECS/Entity/EntityManager.h"
#include "Event/KeyEvent/KeyEvent.h"
#include "Scene/Camera/Camera.h"
#include "GameMaps/MapParser.h"
#include "Utils/Utils.h"

Player *Player::s_instance = nullptr;
Player::Player()
{
    ptr_entity = EntityManager::instance()->createEntity();
}

Player::~Player()
{
    safeDelete(ptr_entity);
}

Player *Player::instance()
{
    return s_instance = (s_instance == nullptr)? new Player():s_instance;
}

void Player::init()
{
    if(ptr_entity != nullptr)
    {
        ptr_entity->addComponent<PlayerComponent>();
        ptr_entity->addComponent<CameraComponent>(1);
        ptr_entity->addComponent<ColliderComponent>(16, 32);
        ptr_entity->addComponent<PositionComponent>();
        ptr_entity->addComponent<SpawnComponent>(Point2DI(368, 176));
        ptr_entity->addComponent<SpriteComponent>("Player", PLAYER_MOTION, 32, 32, 2, 200);
        ptr_entity->addComponent<MotionComponent>(0.6);
        ptr_entity->addComponent<HealthComponent>(100);
        ptr_entity->addComponent<TransformComponent>();
    }
}

void Player::update(float dt)
{
    if(hasComponents() && ptr_entity != nullptr)
    {
        auto box    = ptr_entity->getComponent<ColliderComponent>();
        auto motion = ptr_entity->getComponent<MotionComponent>();
        auto sprite = ptr_entity->getComponent<SpriteComponent>();
        auto pos    = ptr_entity->getComponent<PositionComponent>();

        pos->lastX = pos->x;
        pos->lastY = pos->y;


        ListPoint2DF vertices;

        box->x = pos->x + box->w/2;
        box->y = pos->y;
        box->setRect({box->x, box->y, box->w, box->h});
        box->setCenter(Point2DF(box->x + box->w/2, box->y + box->h/2));
        vertices.push_back(Point2DF(box->x, box->y));
        vertices.push_back(Point2DF(box->x, box->y + box->h));
        vertices.push_back(Point2DF(box->x + box->w, box->y));
        vertices.push_back(Point2DF(box->x + box->w, box->y + box->h));
        box->setVertices(vertices);

        int mapWidth, mapHeight;
        mapWidth = MapParser::instance()->getMapSize().width;
        mapHeight = MapParser::instance()->getMapSize().height;

        if(pos->x < 0)
        {
            pos->x = 0;
        }

        if(pos->y < 0)
        {
            pos->y = 0;
        }

        if(pos->x > mapWidth - sprite->frameWidth)
        {
            pos->x = mapWidth - sprite->frameWidth;
        }

        if(pos->y > mapHeight - sprite->frameHeight)
        {
            pos->y = mapHeight - sprite->frameHeight;
        }

    }
}

void Player::render()
{

}

bool Player::hasComponents()
{
    bool hasComponent = ComponentManager::instance()->hasComponentType<PlayerComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpawnComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<ColliderComponent>(ptr_entity->componentBitset);

    return hasComponent;
}

void Player::followTarget(Entity *target)
{
    if(target == nullptr)
    {
        return;
    }
}

void Player::handleKeyEvent()
{

    if(hasComponents() && ptr_entity != nullptr)
    {
        auto box    = ptr_entity->getComponent<ColliderComponent>();
        auto motion = ptr_entity->getComponent<MotionComponent>();
        auto sprite = ptr_entity->getComponent<SpriteComponent>();
        auto pos    = ptr_entity->getComponent<PositionComponent>();

//        bool moveTopLeft        = KeyEvent::instance()->sendEvent(SDL_SCANCODE_A) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_W);
//        bool moveTopRight       = KeyEvent::instance()->sendEvent(SDL_SCANCODE_D) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_W);
//        bool moveBottomLeft     = KeyEvent::instance()->sendEvent(SDL_SCANCODE_A) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_S);
//        bool moveBottomRight    = KeyEvent::instance()->sendEvent(SDL_SCANCODE_D) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_S);

//        motion->speed = 1;
//        if(moveTopLeft || moveTopRight || moveBottomLeft || moveBottomRight)
//        {
//            motion->speed = 1 / 2.0f;
//        }

        sprite->frameCount = 1;
        motion->running = 0;
        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            motion->running = 1;
            motion->direction = LEFT;
            pos->x += (motion->speed * LEFT);
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 1;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            motion->running = 1;
            motion->direction = RIGHT;
            pos->x += (motion->speed * RIGHT);
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 1;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            motion->running = 1;
            motion->direction = UP;
            pos->y += (motion->speed * UP);
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 1;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            motion->running = 1;
            motion->direction = DOWN;
            pos->y += (motion->speed * DOWN);
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 1;
        }
    }
}

void Player::handleMouseEvent()
{

}
