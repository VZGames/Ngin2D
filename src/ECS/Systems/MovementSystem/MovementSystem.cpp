#include "MovementSystem.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/Components.h"
#include "../../Components/ComponentManager.h"

namespace ngin2D {
MovementSystem::MovementSystem()
{

}

void MovementSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
       bool hasComponent = ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);
       if(hasComponent)
       {
//           entity.getComponent()
       }
    }
}
}
