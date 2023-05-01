#include "CollisionSystem.h"
#include "Graphics/Graphics.h"
#include "Scene/Scene.h"
#include "Utils/Logger/Logger.h"
#include <limits>
#include <future>

namespace ngin2D {

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::init()
{
    m_entities = EntityManager::instance()->getEntities();
    for(auto &layer: MapParser::instance()->getObjectLayers())
    {
        for(auto obj: layer.objects)
        {
            IShape *e = nullptr;
            if(obj.shape == TYPE_SHAPE::ELLIPSE)
            {
                e = new Ellipse(obj.width, obj.height, obj.x, obj.y);
            }
            else if(obj.shape == TYPE_SHAPE::RECTANGLE)
            {
                e = new Rectangle(obj.width, obj.height, obj.x, obj.y);
                e->setVertices(obj.vertices);
            }
            else if(obj.shape == TYPE_SHAPE::POLYGON)
            {
                e = new Polygon(obj.x, obj.y, obj.vertices);
            }
            else
            {
                continue;
            }

            CollisionBlocks.push_back(e);
        }
    }
}

void CollisionSystem::update(float dt)
{
    for(Entity entity: m_entities)
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<PositionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);
        hasComponent &= ComponentManager::instance()->hasComponentType<ColliderComponent>(entity.componentBitset);

        if(hasComponent)
        {
            auto pos      = entity.getComponent<PositionComponent>();

            SizeF tileSize = MapParser::instance()->getTileSize();

            bool collided = false;

            collided = MapCollision(&entity);

            if(collided)
            {
                pos->x += m_collisionManager.mtv().x;
                pos->y += m_collisionManager.mtv().y;
            }
        }
    }
}

void CollisionSystem::render()
{
    for(auto block: CollisionBlocks)
    {
        if(block->type() == TYPE_SHAPE::ELLIPSE)
        {
            Ellipse *e = (Ellipse*)block;
            TextureManager::instance()->drawEllipse(e->center() -= Camera::instance()->position(), e->size().width/2, e->size().height/2);
        }
        else if(block->type() == TYPE_SHAPE::RECTANGLE)
        {
            Rectangle *e = (Rectangle*)block;
            TextureManager::instance()->drawRectangle(e->position() -= Camera::instance()->position(), e->size().width, e->size().height);
        }
        else if(block->type() == TYPE_SHAPE::POLYGON)
        {
            Polygon *e = (Polygon*)block;
            TextureManager::instance()->drawPolygon(e->vertices());
        }
    }
}

bool CollisionSystem::MapCollision(Entity *entity)
{
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();
    auto motion     = entity->getComponent<MotionComponent>();
    auto box        = entity->getComponent<ColliderComponent>();

    Point2DF entityI = Point2DF(pos->x + sprite->frameWidth/2,
                                pos->y + sprite->frameHeight/2);

    // if entity are not moving then do nothing after
    if(!motion->running) return 0;

    for(auto block: CollisionBlocks)
    {
        float x, y;
        float w, h;

        x = block->position().getX();
        y = block->position().getY();

        w = block->size().width;
        h = block->size().height;

        if((box->x - (x + w) > 1.0f
            || box->y - (y + h) > 1.0f
            || x - (box->x + box->w) > 1.0f
            || y - (box->y + box->h) > 1.0f))
        {
            continue;
        }


        IShape *shape = block;

        if(box->axes().size() < 1) break;

        if(shape->type() == TYPE_SHAPE::ELLIPSE
                || box->type() == TYPE_SHAPE::ELLIPSE)
        {
            return m_collisionManager.IntersectCurvePolygon((Ellipse*)shape, (Polygon*)box);
        }
        else
        {
            if(shape->axes().size() < 1) break;
            return m_collisionManager.IntersectPolygons((Polygon*)box,  (Polygon*)shape);
        }


    }

    return 0;
}

bool CollisionSystem::OtherEntitiesCollision(Entity *entity)
{
    return 0;
}

}
