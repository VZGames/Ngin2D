#include "CollisionSystem.h"

namespace ngin2D {

CollisionSystem::CollisionSystem()
{
    for(auto layer: MapParser::instance()->getObjectLayers())
    {
        for(auto obj: layer.objects)
        {
            if(obj.shape == std::string("ellipse"))
            {
                Ellipse e(obj.width/2, obj.height/2);
                colliders.push_back(e);
            }
        }
    }
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
