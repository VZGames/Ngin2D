#include "SpawnSystem.h"
#include "../../Components/Components.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/ComponentManager.h"

namespace ngin2D {
SpawnSystem::SpawnSystem()
{

}

void SpawnSystem::init()
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpawnComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<CameraComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto spawn = entity.getComponent<SpawnComponent>();
            auto camera = entity.getComponent<CameraComponent>();

            camera->position = Point2DI(spawn->position.getX(), spawn->position.getY());
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
