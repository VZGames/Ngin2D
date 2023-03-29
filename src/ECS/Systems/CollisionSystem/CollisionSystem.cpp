#include "CollisionSystem.h"

namespace ngin2D {

CollisionSystem::CollisionSystem()
{

}

void CollisionSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<CameraComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto collition  = entity.getComponent<CameraComponent>();
            auto motion     = entity.getComponent<MotionComponent>();
            auto sprite     = entity.getComponent<SpriteComponent>();
            auto pos        = entity.getComponent<PositionComponent>();

            Point2DI blockPos;

            Size tileSize = MapParser::instance()->getTileSize();

            int left   = (pos->x) / tileSize.width;
            int right  = (pos->x + sprite->frameWidth) / tileSize.width;
            int top    = (pos->y) / tileSize.height;
            int bottom = (pos->y + sprite->frameHeight) / tileSize.height;

            bool collided = false;

            if(collided)
            {
                pos->x = pos->lastX;
                pos->y = pos->lastY;
            }


        }
    }
}

bool CollisionSystem::MapCollision()
{
    return 0;
}

}
