#include "MovementSystem.h"
#include "../../Components/Components.h"
#include "../../Entity/EntityManager.h"
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
       hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
       if(hasComponent)
       {
           auto motion = entity.getComponent<MotionComponent>();
           auto position = entity.getComponent<PositionComponent>();
//           position->pos = Point2D(position->pos.getX() + motion->velocity.x * motion->direction,
//                                   position->pos.getY() + motion->velocity.y * motion->direction);

       }
    }
}
}
