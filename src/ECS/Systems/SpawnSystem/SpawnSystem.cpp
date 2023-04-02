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

        if(hasComponent)
        {
            auto spawn = entity.getComponent<SpawnComponent>();
            Camera::instance()->moveTo(Point2DF(spawn->position.getX(), spawn->position.getY()));
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
