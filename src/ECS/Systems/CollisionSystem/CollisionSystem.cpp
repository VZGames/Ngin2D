#include "CollisionSystem.h"
#include "Graphics/Graphics.h"
#include "Scene/Scene.h"

namespace ngin2D {

CollisionSystem::CollisionSystem()
{
    for(auto layer: MapParser::instance()->getObjectLayers())
    {
        for(auto obj: layer.objects)
        {
            IShape *e = nullptr;
            if(obj.shape == std::string("ellipse"))
            {
                e = new Ellipse(obj.width/2, obj.height/2, (int)obj.x, (int)obj.y);
            }
            else if(obj.shape == std::string("rectangle"))
            {
                e = new Rectangle(obj.width, obj.height, (int)obj.x, (int)obj.y);
            }

            if(e != nullptr)
            {
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

void CollisionSystem::render()
{
    for(auto block: CollisionBlocks)
    {
        if(block->getTypeName() == std::string("ellipse"))
        {
            Ellipse *e = (Ellipse*)block;
            TextureManager::instance()->drawEllipse(e->getCenterI() -= Camera::instance()->position(), e->size().width/2, e->size().height/2);
        }
        else if(block->getTypeName() == std::string("rectangle"))
        {
            Rectangle *e = (Rectangle*)block;
            TextureManager::instance()->drawRectangle(e->getPosition() -= Camera::instance()->position(), e->size().width, e->size().height);
        }
    }
}

bool CollisionSystem::MapCollision(Entity *entity)
{
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();


    for(auto block: CollisionBlocks)
    {
        bool collided = block->contain(Point2DI(pos->x, pos->y));
        return collided;
    }
    return 0;
}

}
