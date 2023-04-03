#include "CollisionSystem.h"
#include "Graphics/Graphics.h"
#include "Scene/Scene.h"

namespace ngin2D {

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::init()
{
    for(auto layer: MapParser::instance()->getObjectLayers())
    {
        for(auto obj: layer.objects)
        {
            IShape *e = nullptr;
            if(obj.shape == std::string("ellipse"))
            {
                e = new Ellipse(obj.width, obj.height, obj.x, obj.y);
            }
            else if(obj.shape == std::string("rectangle"))
            {
                e = new Rectangle(obj.width, obj.height, obj.x, obj.y);
            }

            else if(obj.shape == std::string("polygon"))
            {
                e = new Polygon(obj.x, obj.y, obj.points);
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
            auto pos      = entity.getComponent<PositionComponent>();

            SizeF tileSize = MapParser::instance()->getTileSize();

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
        else if(block->getTypeName() == std::string("polygon"))
        {
            Polygon *e = (Polygon*)block;
            TextureManager::instance()->drawPolygon(e->getPosition(), e->points());
        }
    }
}

bool CollisionSystem::MapCollision(Entity *entity)
{
    auto motion     = entity->getComponent<MotionComponent>();
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();

    bool collided   = 0;

    for(auto block: CollisionBlocks)
    {
        if(block->getTypeName() == std::string("ellipse"))
        {
            Ellipse *e = (Ellipse*)block;
            float distance = e->getCenterI()
                    .distance(Point2DF(pos->x + sprite->frameWidth/2,
                                       pos->y + sprite->frameHeight/2));

            float radiusMax = (e->radiusX() > e->radiusY()) ? e->radiusX():e->radiusY();
            float radiusMin = (e->radiusX() < e->radiusY()) ? e->radiusX():e->radiusY();

            collided += (distance <= radiusMin + sprite->frameWidth/2);
            collided += (distance <= radiusMax + sprite->frameWidth/2);
            return collided;
        }
        else if(block->getTypeName() == std::string("rectangle"))
        {
            SDL_FRect entiyBox = {
                pos->x,
                pos->y,
                sprite->frameWidth,
                sprite->frameHeight
            };
            return SDL_HasIntersectionF(&block->getRect(), &entiyBox);
        }
    }
    return collided;
}

}
