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
                e->setVertices(obj.vertices);
            }
            else if(obj.shape == std::string("rectangle"))
            {
                e = new Rectangle(obj.width, obj.height, obj.x, obj.y);
                e->setVertices(obj.vertices);
            }
            else if(obj.shape == std::string("polygon"))
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
            auto motion   = entity.getComponent<MotionComponent>();
            auto pos      = entity.getComponent<PositionComponent>();
            auto box      = entity.getComponent<ColliderComponent>();

            SizeF tileSize = MapParser::instance()->getTileSize();

            bool collided = false;
            collided += MapCollision(&entity);

            if(collided)
            {
                pos->x = box->collidedY? pos->lastX + motion->direction: pos->lastX;
                pos->y = box->collidedX? pos->lastY + motion->direction: pos->lastY;
            }
            else
            {
                box->collidedY = 0;
                box->collidedX = 0;
            }
        }
    }
}

void CollisionSystem::render()
{
    for(auto block: CollisionBlocks)
    {
        if(block->type() == std::string("ellipse"))
        {
            Ellipse *e = (Ellipse*)block;
            TextureManager::instance()->drawEllipse(e->center() -= Camera::instance()->position(), e->size().width/2, e->size().height/2);
        }
        else if(block->type() == std::string("rectangle"))
        {
            Rectangle *e = (Rectangle*)block;
            TextureManager::instance()->drawRectangle(e->position() -= Camera::instance()->position(), e->size().width, e->size().height);
        }
        else if(block->type() == std::string("polygon"))
        {
            Polygon *e = (Polygon*)block;
            TextureManager::instance()->drawPolygon(e->position(), e->vertices());
        }
    }
}

bool CollisionSystem::MapCollision(Entity *entity)
{
    auto sprite     = entity->getComponent<SpriteComponent>();
    auto pos        = entity->getComponent<PositionComponent>();
    auto box        = entity->getComponent<ColliderComponent>();

    Point2DF entityI = Point2DF(pos->x + sprite->frameWidth/2,
                                pos->y + sprite->frameHeight/2);
    bool collided   = 0;

    for(auto block: CollisionBlocks)
    {
        IShape *shape = block;
        if(block->type() == std::string("ellipse"))
        {
            Ellipse *e = (Ellipse*)block;
        }
        else if(block->type() == std::string("rectangle"))
        {
            Rectangle *e = (Rectangle*)block;
        }
        else if(block->type() == std::string("polygon"))
        {
            Polygon *e = (Polygon*)block;
        }
    }
    return collided;
}

bool CollisionSystem::OtherEntitiesCollision(Entity *entity)
{
    return 0;
}

}
