#include "MovementSystem.h"
#include "../../Components/Components.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/ComponentManager.h"
#include "../../../Game/Game.h"

namespace ngin2D {
MovementSystem::MovementSystem()
{

}

void MovementSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasCamera = ComponentManager::instance()->hasComponentType<CameraComponent>(entity.componentBitset);
        bool hasComponent = ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto motion = entity.getComponent<MotionComponent>();
            auto position = entity.getComponent<PositionComponent>();
            if(hasCamera)
            {
                auto camera = entity.getComponent<CameraComponent>();
                Game::s_camera = {
                    camera->position.getX(),
                    camera->position.getY(),
                    camera->size.width,
                    camera->size.height
                };
            }
            position->x += (motion->velocity.x);
            position->y += (motion->velocity.y);
        }
    }
}
}
