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
                Ellipse *e = new Ellipse(obj.width/2, obj.height/2, (int)obj.x, (int)obj.y);
                CollisionBlocks.push_back(e);
            }
        }
    }
}

void CollisionSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto motion     = entity.getComponent<MotionComponent>();
            auto sprite     = entity.getComponent<SpriteComponent>();
            auto pos        = entity.getComponent<PositionComponent>();

            Size tileSize = MapParser::instance()->getTileSize();

            bool collided = false;
            collided += MapCollision(&entity);

            if(collided)
            {
                pos->x = pos->lastX;
                pos->y = pos->lastY;
            }

        }
    }
}

bool CollisionSystem::MapCollision(Entity *entity)
{
    auto motion     = entity->getComponent<MotionComponent>();
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();

    Point2DI left   = Point2DI(pos->x + sprite->frameWidth, pos->y);

    for(auto x: CollisionBlocks)
    {
        return x->contain(Point2DI(pos->x, pos->y));
    }
    return 0;
}

}
