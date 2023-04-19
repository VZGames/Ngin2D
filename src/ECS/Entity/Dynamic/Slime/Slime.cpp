#include "Slime.h"
#include "ECS/Entity/EntityManager.h"
#include "Event/KeyEvent/KeyEvent.h"
#include "Scene/Camera/Camera.h"
#include "GameMaps/MapParser.h"
#include "Utils/Utils.h"

namespace ngin2D {
Slime::Slime()
{
    ptr_entity = EntityManager::instance()->createEntity();
    ptr_entity->addComponent<ColliderComponent>(32, 32);
    ptr_entity->addComponent<PositionComponent>(200, 50);
    ptr_entity->addComponent<SpawnComponent>(Point2DI(0, 0));
    ptr_entity->addComponent<SpriteComponent>("Slime", "./assets/Characters/slime.png", 32, 32, 1, 200);
    ptr_entity->addComponent<MotionComponent>(2.0, Vector2DF(), Vector2DF());
    ptr_entity->addComponent<HealthComponent>(100);
    ptr_entity->addComponent<TransformComponent>();
}

Slime::~Slime()
{
    safeDelete(ptr_entity);
}

void Slime::init()
{

}

void Slime::followTarget(Entity *target)
{

}

void Slime::handleKeyEvent()
{

}

void Slime::handleMouseEvent()
{

}
}

