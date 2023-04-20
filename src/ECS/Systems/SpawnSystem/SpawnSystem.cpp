#include "SpawnSystem.h"
#include "ECS/Components/Components.h"
#include "ECS/Entity/EntityManager.h"
#include "Scene/Camera/Camera.h"

namespace ngin2D {
SpawnSystem::SpawnSystem()
{

}

void SpawnSystem::init()
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpawnComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto spawn = entity.getComponent<SpawnComponent>();
            auto pos     = entity.getComponent<PositionComponent>();
            pos->x       = spawn->position.getX();
            pos->y       = spawn->position.getY();
        }
    }
}

void SpawnSystem::update(float dt)
{

}

void SpawnSystem::render()
{

}
}
