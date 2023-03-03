#include "RenderSystem.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/Components.h"
#include "../../Components/ComponentManager.h"

namespace ngin2D {
RenderSystem::RenderSystem()
{}

void RenderSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<HealthComponent>(entity.componentBitset);
        if(hasComponent)
        {
        }
    }
}

void RenderSystem::render()
{

}
}

