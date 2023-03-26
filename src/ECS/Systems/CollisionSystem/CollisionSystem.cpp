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
            auto position   = entity.getComponent<PositionComponent>();

            int left  = (position->x - sprite->frameWidth) / sprite->frameWidth;
            int right = (position->x + sprite->frameWidth * 2) / sprite->frameWidth;
            int top   = (position->y - sprite->frameHeight) / sprite->frameHeight;

            MapParser::instance()->isCollider(
                        Point2DI(position->x / sprite->frameWidth,
                                 position->y / sprite->frameHeight));
        }
    }
}

}
