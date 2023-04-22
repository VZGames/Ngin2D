#include "MovementSystem.h"
#include "ECS/Components/Components.h"
#include "ECS/Entity/EntityManager.h"

namespace ngin2D {
MovementSystem::MovementSystem()
{

}

void MovementSystem::init()
{
    m_entities = EntityManager::instance()->getEntities();
}

void MovementSystem::update(float dt)
{
    for(Entity entity: m_entities)
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto motion = entity.getComponent<MotionComponent>();
            auto sprite = entity.getComponent<SpriteComponent>();
            auto position = entity.getComponent<PositionComponent>();

            position->x += motion->velocity.x;
            position->y += motion->velocity.y;
        }
    }
}
}
