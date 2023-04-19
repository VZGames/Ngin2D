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
    ptr_entity->addComponent<PlayerComponent>();
    ptr_entity->addComponent<CameraComponent>();
    ptr_entity->addComponent<ColliderComponent>(16, 32);
    ptr_entity->addComponent<PositionComponent>((g_width - 8) / (2 * ZOOM_FACTOR), (g_height - 8) / (2 * ZOOM_FACTOR));
    ptr_entity->addComponent<SpawnComponent>(Point2DI(200, 176));
    ptr_entity->addComponent<SpriteComponent>("Lover", PLAYER_MOTION, 32, 32, 2, 200);
    ptr_entity->addComponent<MotionComponent>(PLAYER_SPEED, Vector2DF(), Vector2DF());
    ptr_entity->addComponent<HealthComponent>(100);
    ptr_entity->addComponent<TransformComponent>();
}

Player::~Player()
{
    safeDelete(ptr_entity);
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
    hasComponent &= ComponentManager::instance()->hasComponentType<ColliderComponent>(ptr_entity->componentBitset);

    if(hasComponent)
    {
        auto box    = ptr_entity->getComponent<ColliderComponent>();
        auto motion = ptr_entity->getComponent<MotionComponent>();
        auto sprite = ptr_entity->getComponent<SpriteComponent>();
        auto pos    = ptr_entity->getComponent<PositionComponent>();

        bool pressed = KeyEvent::instance()->isPressed();
        if(pressed)
        {
            motion->running = 1;
        } else
        {
            motion->running = 0;
        }

        pos->lastX = pos->x;
        pos->lastY = pos->y;

        ListPoint2DF vertices;

        box->x = pos->x + box->w/2;
        box->y = pos->y;
        box->setRect({box->x, box->y, box->w, box->h});
        box->setCenter(Point2DF(box->x + box->w/2, box->y + box->h/2));
        vertices.push_back(Point2DF(box->x, box->y));
        vertices.push_back(Point2DF(box->x + box->w, box->y));
        vertices.push_back(Point2DF(box->x, box->y + box->h));
        vertices.push_back(Point2DF(box->x + box->w, box->y + box->h));
        box->setVertices(vertices);


        sprite->frameCount = 1;

        bool moveTopLeft        = KeyEvent::instance()->sendEvent(SDL_SCANCODE_A) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_W);
        bool moveTopRight       = KeyEvent::instance()->sendEvent(SDL_SCANCODE_D) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_W);
        bool moveBottomLeft     = KeyEvent::instance()->sendEvent(SDL_SCANCODE_A) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_S);
        bool moveBottomRight    = KeyEvent::instance()->sendEvent(SDL_SCANCODE_D) && KeyEvent::instance()->sendEvent(SDL_SCANCODE_S);

        motion->speed = PLAYER_SPEED;
        if(moveTopLeft || moveTopRight || moveBottomLeft || moveBottomRight)
        {
            motion->speed = PLAYER_SPEED / 2.0f;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
        {
            motion->direction = LEFT;
            pos->x += (motion->speed * LEFT);
            sprite->frameCount = 4;
            sprite->row = 2;
            sprite->col = 1;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
        {
            motion->direction = RIGHT;
            pos->x += (motion->speed * RIGHT);
            sprite->frameCount = 4;
            sprite->row = 3;
            sprite->col = 1;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
        {
            motion->direction = UP;
            pos->y += (motion->speed * UP);
            sprite->frameCount = 4;
            sprite->row = 0;
            sprite->col = 1;
        }

        if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
        {
            motion->direction = DOWN;
            pos->y += (motion->speed * DOWN);
            sprite->frameCount = 4;
            sprite->row = 1;
            sprite->col = 1;
        }

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

void Player::handleMouseEvent()
{

}
