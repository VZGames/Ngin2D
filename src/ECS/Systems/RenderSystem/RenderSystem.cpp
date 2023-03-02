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
       std::cout << entity.id <<  " " <<  ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.components) << std::endl;
    }
}

void RenderSystem::render()
{

}
}

