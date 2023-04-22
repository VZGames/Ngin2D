#include "Slime.h"
#include "ECS/Entity/EntityManager.h"
#include "Event/KeyEvent/KeyEvent.h"
#include "Scene/Camera/Camera.h"
#include "GameMaps/MapParser.h"
#include "Utils/Utils.h"

Slime::Slime()
{
    ptr_entity = EntityManager::instance()->createEntity();
}

Slime::~Slime()
{
    safeDelete(ptr_entity);
}

void Slime::init()
{
    if(ptr_entity != nullptr)
    {
        const char* textureId = randomStr(5);
        ptr_entity->addComponent<ColliderComponent>(32, 32);
        ptr_entity->addComponent<PositionComponent>();
        ptr_entity->addComponent<SpawnComponent>(Point2DI(50, 100));
        ptr_entity->addComponent<SpriteComponent>(textureId, "./assets/Characters/slime.png", 32, 32, 4, 200);
        ptr_entity->addComponent<MotionComponent>(2.0, Vector2DF(), Vector2DF());
        ptr_entity->addComponent<HealthComponent>(100);
        ptr_entity->addComponent<TransformComponent>();
    }
}

void Slime::update(float dt)
{
    if(hasComponents())
    {
        auto sprite = ptr_entity->getComponent<SpriteComponent>();
        sprite->frameCount = 6;
        sprite->col = 0;
        sprite->row = 1;
    }
}

void Slime::render()
{

}

bool Slime::hasComponents()
{
    bool hasComponent = ComponentManager::instance()->hasComponentType<MotionComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<SpawnComponent>(ptr_entity->componentBitset);
    hasComponent &= ComponentManager::instance()->hasComponentType<ColliderComponent>(ptr_entity->componentBitset);

    return hasComponent;
}

void Slime::followTarget(Entity *target)
{

}

