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

    bool collided   = 0;

    for(auto block: CollisionBlocks)
    {
        float x, y;
        float w, h;

        x = block->getPosition().getX();
        y = block->getPosition().getY();

        w = block->size().width;
        h = block->size().height;

        if(block->getTypeName() == std::string("ellipse"))
        {
            Point2DF topLeft(pos->x, pos->y);
            Point2DF topRight(pos->x + sprite->frameWidth, pos->y);
            Point2DF bottomLeft(pos->x, pos->y + sprite->frameHeight);
            Point2DF bottomRight(pos->x + sprite->frameWidth, pos->y + sprite->frameHeight);

            collided |= block->contain(topLeft);
            collided |= block->contain(topRight);
            collided |= block->contain(bottomLeft);
            collided |= block->contain(bottomRight);
        }
        else if(block->getTypeName() == std::string("rectangle"))
        {
            SDL_FRect entiyBox = {
                pos->x,
                pos->y,
                sprite->frameWidth,
                sprite->frameHeight
            };
            collided += SDL_HasIntersectionF(&block->getRect(), &entiyBox);
        }
    }
    return collided;
}

}
