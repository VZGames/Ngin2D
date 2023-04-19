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
    for(Entity entity: EntityManager::instance()->getEntities())
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

            Vector2DF mtv;

            collided = MapCollision(&entity, mtv);

            if(collided)
            {
                LOG_INFO("COLLIDED");
                pos->x += mtv.x;
                pos->y += mtv.y;
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

bool CollisionSystem::MapCollision(Entity *entity, Vector2DF &mtv)
{
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();
    auto box        = entity->getComponent<ColliderComponent>();

    Point2DF entityI = Point2DF(pos->x + sprite->frameWidth/2,
                                pos->y + sprite->frameHeight/2);

    for(auto block: CollisionBlocks)
    {
        float x, y;
        float w, h;

        x = block->position().getX();
        y = block->position().getY();

        w = block->size().width;
        h = block->size().height;

        if(box->x - (x + w) > 50.0f
                || box->y - (y + h) > 50.0f
                || x - (box->x + box->w) > 50.0f
                || y - (box->y + box->h) > 50.0f)
        {
            continue;
        }


        IShape *shape = block;

        if(shape->type() == TYPE_SHAPE::ELLIPSE)
        {
            shape->clearVertices();
            shape->appendVertices(shape->center());
            shape->appendVertices(shape->center().nearestPoint(box->vertices()));
        }

        if(box->axes().size() < 1) break;
        if(shape->axes().size() < 1) break;


        float minOverlap = std::numeric_limits<float>::infinity();

        for (auto &axis: box->axes())
        {
            Projection2D project1 = box->project(axis);
            Projection2D project2 = shape->project(axis);

            float overlap = project1.gap(project2);
            if (overlap == 0.0f) // shapes are not overlapping
            {
                mtv = Vector2DF();
                goto next;
            }
            else
            {
                if (overlap < minOverlap)
                {
                    minOverlap = overlap;
                    mtv = axis * minOverlap;
                }
            }
        }

        for (auto &axis: shape->axes())
        {
            Projection2D project1 = box->project(axis);
            Projection2D project2 = shape->project(axis);

            float overlap = project1.gap(project2);
            if (overlap == 0.0f) // shapes are not overlapping
            {
                mtv = Vector2DF();
                goto next;
            }
            else
            {
                if (overlap < minOverlap)
                {
                    minOverlap = overlap;
                    mtv = axis * minOverlap;
                }
            }
        }

        goto collided;

next:
        continue;

collided:
        // need to reverse MTV if center offset and overlap are not pointing in the same direction
        bool notPointingInTheSameDirection = mtv.dotProduct((box->center() - shape->center()).toVector(), mtv) < 0;
        if (notPointingInTheSameDirection) { mtv = mtv * -1; }
        return 1;
    }

    return 0;
}

bool CollisionSystem::OtherEntitiesCollision(Entity *entity)
{
    return 0;
}

}
